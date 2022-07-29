#include<stdio.h>

int main(){
    system("color 3F");
    int pin=6321, option, enteredPin, count=0, amount=1;
    float balance = 50000;
    int continueTransection = 1;

    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t\t%s", ctime(&now));
    printf("\n\t\t\t============================*Welcome to DBBL*==============================");

    while(pin != enteredPin){
        printf("\nPlease enter your pin: ");
        scanf("%d",&enteredPin);
        if(enteredPin != pin){
            Beep(610,500);
            printf("Invalid Pin!");
        }
        count++;
        if(count == 3 && pin != enteredPin){
            exit(0);
        }
    }

    while(continueTransection != 0){
        printf("\n\t\t\t=========================*Available Transactions*==========================");
        printf("\n\n\t\t1.Withdrawal");
        printf("\n\t\t2.Diposit");
        printf("\n\t\t3.Check Balance");
        printf("\n\n\tPlease select the option: ");
        scanf("%d",&option);
        switch(option){
        case 1:
            while(amount % 500 != 0){
                 printf("\n\t\tEnter the amount:");
                 scanf("%d",&amount);
                 if(amount % 500 != 0)
                    printf("\n\t The amount should be multiple of 500");
            }
            if(balance < amount){
                printf("\n\t Insufficient balance!");
                amount = 1;
                break;
            }
            else{
                balance -= amount;
                printf("\n\t\tYou have withdrawn BDT.%d. Your new balance is %.2f",amount,balance);
                printf("\n\n\t\t====================Thank you for banking with us.=====================");
                amount = 1;
                break;
            }
        case 2:
            printf("\n\t\t Please enter the amount: ");
            scanf("%d",&amount);
            balance += amount;
            printf("\n\t\tYou have deposited BDT.%d. Your new balance is %.2f",amount,balance);
            printf("\n\n\t\t====================Thank you for banking with us.=====================");
            amount = 1;
            break;
        case 3:
            printf("\n\t\tYour balance is BDT.%.2f",balance);
            break;

        default:
            Beep(610,500);
            printf("\n\t\tInvalid option!!");
        }

    printf("\n\n\t\tDo you wish to perform another transaction? Press 1[Yes], 0[No]");
    scanf("%d",&continueTransection);

    }

    return 0;
}
