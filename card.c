#include"types.h"
// reading card data from user
// placing data entered in the struct that will be passed to this function
void card(struct card_data *client) {
    printf("Please enter card data:\n");
    printf("Please enter card holder name:\t");
    scanf( "%[^\n]%*c",client->CHD);
    printf("\nPlease enter account number:\t");
    scanf("%s", client->PAN);
    printf( "\nPlease enter card Expiry Date (MM/YY) :\t");
    scanf("%s",client->CED);
	
	
}