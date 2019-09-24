/*
 *Name: Houston Walley
 *File Name: project1.cpp
 *Compile using g++
 *Used Dr. Li's source code. Not completely,
 *but enought to feel like I should cite it.
 */

#include <iostream>
#include <iomanip>
using namespace std;

//main method
int main()
{

   //formats double
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   //initial variables
   double loan;
   double rate;
   double monthlyPay;
   
   //takes in loan amount, interest, monthly pay
   cout << "Loan Amount: ";
   cin >> loan;
   
   //catches invalid loan amount
   while (loan <= 0)
   {
      cout << "Loan must be greater than zero.\n";
      
      cout << "\nLoan Amount: ";
      cin >> loan;
   }
   
   cout << "Interest Rate (% per year): ";
   cin >> rate;
   
   //catches invalid interest rate
   while (rate <= 0)
   {
      cout << "Rate must be greater than zero.\n";
      
      cout << "\nInterest Rate (% per year): ";
      cin >> rate;
   }
   
   cout << "Monthly Payments: ";
   cin >> monthlyPay;
   
   //catches the case of a never ending debt
   while ((loan * (rate / 1200)) >= monthlyPay)
   {
      cout << "The loan cannot be paid off at this rate.\n";
      
      cout << "\nMonthly Payments: ";
      cin >> monthlyPay;
   }
   
   //fixes the rate
   rate = rate / 12;
   
   //prints the header
   cout << "\n" << left << "*****************************************************************";
   cout << setw(10) << "\n" << "Amortization Table";
   cout << "\n" << left << "*****************************************************************";
   cout << "\nMonth\tBalance\t\tPayment\tRate\tInterest\tPrincipal";
   
   //prints month zero
   cout << "\n" << setw(8) << "0" << "$" << setw(15) << loan << setw(8) 
      << "N/A" << setw(8) << "N/A" << setw(16) << "N/A" << "N/A";
   
   //variables for the loop
   double total = 0;
   double prince;
   double interest;
   int i = 1;
   
   //loops through the remaining months
   while (loan > 0)
   {
      
      //calculates interest
      interest = loan * (rate / 100); 
      
      //calculates total interest
      total += interest;
            
      //calculates principal
      prince = monthlyPay - interest;
      
      //calculates loan
      loan = loan - prince;
      
      //catches payment case
      if (monthlyPay >= (loan + interest))
      {
         cout << "\n" << setw(8) << i << "$" << setw(15) << loan << "$" 
            << setw(7) << monthlyPay << setw(8) << rate << "$" << setw(15)
            << interest << "$" << prince;
         
         //calculates the final month variables
         interest = loan * (rate / 100);
         total += interest;
         monthlyPay = interest + loan;
         prince = loan;
         loan = 0.00;
         
         i++;
      }
      
      //prints the output
      cout << "\n" << setw(8) << i << "$" << setw(15) << loan << "$" 
         << setw(7) << monthlyPay << setw(8) << rate << "$" << setw(15)
         << interest << "$" << prince;
      
      //counts up a month
      i++;
      
   }
   
   //prints footer and final sentences.
   cout << "\n****************************************************************\n";
   cout << "\nIt takes " << (i - 1) << " months to pay off the loan.";
   cout << "\nTotal interest paid is: " << "$" << total << endl;

   //ends program
   return 0;
  
}
