#include "types.h"
// data base of the payment application
struct account_balance dataBase[] =
        {
                {"15287895887467", 1000.00},
                {"82485224515579",400.00},
                {"55488514854788",36558.00},
                {"12575278856875",0.00},
                {"98236525857788",500.00},
                {"78726871389555",305.00},
                {"12574587455887",1700},
                {"87252354124554",15.25 },
                {"13584268632285", 1.00},
                {"98785878852578", 0.64},
        };
// prototype of clear function, it is used to clear the structures after the transaction
void clear (struct card_data *c, struct terminal_data *t);
int main() {
        //Initializing the card and terminal structures
        struct card_data c = {"", "", ""};
        struct terminal_data t = {0.0, 6000.0, ""};
        //Initializing user input, 'y'--> yes, and 'n'--> no
        uint8_t userInput = 'y';
        // creating pointers to structs to pass by reference the structures to external functions
        struct card_data *cptr = &c;
        struct terminal_data *tptr = &t;
        printf("\t\tWelcome\n");
        //program loop
        while(userInput == 'y'){
            //sending the card struct to the card function to store the card data in it
            card(cptr);
            //sending the terminal struct to the terminal function to store the terminal data in it
            /* the terminal function will return either 1, or 255
               -'1' if the terminal conditions are successfully completed
               -'255' if error happened during the conditions
             */
            uint8_t result = terminal(cptr, tptr);
            if (result == 1)
                // if terminal conditions are successfully done, the server function will be executed
                // the result variable here that this function will return is the index of the user
                // the index is used to update the data base with the new balance
                result = server(dataBase, cptr, tptr);
            if (result != 255) {
                // updating the balance of the user with index [result] with his new balance after transaction
                dataBase[result].balance = dataBase[result].balance - t.TA;
        }
        // print array function is used to print the database to show how it is automatically updated after each successful transaction
        printArray(dataBase, 10);
        // clear function is used after each transaction to clear the structs variables
        clear(cptr, tptr);
        // check whether user wants to create another transaction or not
        printf("Do you want to continue (y/n)?\n");
        scanf(" %c", &userInput);
        }
}
// implementation of clear function
// it is used in main() to clear the attributes of the struct after each transaction
void clear (struct card_data *c, struct terminal_data *t){
    memset(c->PAN,0, 20);
    memset(c->CHD,0, 25);
    memset(c->CED,0, 6);
    memset(t->TrD,0,11);
    t->TA = 0.0;
    t->MTA = 6000;
}

