/**
 *
 *Author: Houston Walley
 *File name: project2.cpp
 *Used Dr. Li's source code.
 *Compile using g++
 */
 #include <iostream>
 #include <stdlib.h>
 #include <assert.h>
 #include <ctime>
using namespace std;

//Methods
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void Press_any_key(void);

//Test Prototypes
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);
 
//Variables
const int TOTAL_RUNS = 10000;
const int A_accuracy = 33;
const int B_accuracy = 50;
const int C_accuracy = 100;
int shoot_target_result;

//Main method
int main() {

   //Initializes Random number generator's seed and calls test functions
   cout << "*** Welcome to Houston's Duel Simulator ***\n";
   srand(time(0));
   test_at_least_two_alive();
   Press_any_key();
   test_Aaron_shoots1();
   Press_any_key();
   test_Bob_shoots();
   Press_any_key();
   test_Charlie_shoots();
   Press_any_key();
   test_Aaron_shoots2();
   Press_any_key();
   
   //Starts strategy 1 and runs 10,000 times.
   cout << "Ready to test strategy 1 (run 10000 times):\n";
   Press_any_key();
   int aaronWins1 = 0;
   int bobWins = 0;
   int charlieWins = 0;
   for (int i = 0; i < TOTAL_RUNS; i++) {
      bool aaronAlive = true;
      bool bobAlive = true;
      bool charlieAlive = true;
      while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
         shoot_target_result = rand()%100;
         if (aaronAlive) {
            Aaron_shoots1(bobAlive, charlieAlive);
         }
         shoot_target_result = rand()%100;
         if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
         }
         shoot_target_result = rand()%100;
         if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive); 
         }   
      }
      if (aaronAlive) {
         aaronWins1++;
      }
      if (bobAlive) {
         bobWins++;
      }
      if (charlieAlive) {
         charlieWins++;
      }
   }
   
   cout << "Aaron won " << aaronWins1 << "/10000 duels or " 
      << static_cast<double>(aaronWins1)/TOTAL_RUNS * 100 << "%\n"
      << "Bob won " << bobWins << "/10000 duels or "
      << static_cast<double>(bobWins)/TOTAL_RUNS * 100 << "%\n"
      << "Charlie won " << charlieWins << "/10000 duels or "
      << static_cast<double>(charlieWins)/TOTAL_RUNS * 100 << "%\n"
      << endl;
      
      
   //Starts strategy 2 and runs 10,000 times.
   cout << "Ready to test strategy 2 (run 10000 times):\n";
   Press_any_key();
   int aaronWins2 = 0;
   bobWins = 0;
   charlieWins = 0;
   for (int i = 0; i < TOTAL_RUNS; i++) {
      bool aaronAlive = true;
      bool bobAlive = true;
      bool charlieAlive = true;
      while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
         shoot_target_result = rand()%100;
         if (aaronAlive) {
            Aaron_shoots2(bobAlive, charlieAlive);
         }
         shoot_target_result = rand()%100;
         if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
         }
         shoot_target_result = rand()%100;
         if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive); 
         }  
      }
      if (aaronAlive) {
         aaronWins2++;
      }
      if (bobAlive) {
         bobWins++;
      }
      if (charlieAlive) {
         charlieWins++;
      }
   }
   
   cout << "Aaron won " << aaronWins2 << "/10000 duels or " 
      << static_cast<double>(aaronWins2)/TOTAL_RUNS * 100 << "%\n"
      << "Bob won " << bobWins << "/10000 duels or "
      << static_cast<double>(bobWins)/TOTAL_RUNS * 100 << "%\n"
      << "Charlie won " << charlieWins << "/10000 duels or "
      << static_cast<double>(charlieWins)/TOTAL_RUNS * 100 << "%\n"
      << endl;
      
   if (aaronWins1 > aaronWins2) {
      cout << "Strategy 1 is better than strategy 2.\n";
   }
   else {
      cout << "Strategy 2 is better than strategy 1.\n";
   }
   
   return 0;
}

 /**
  *Returns True if two or more are alive. False otherwise.
  */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   
   if ((A_alive && B_alive) || (B_alive && C_alive) || (A_alive && C_alive)) {
      return true;
   }
   return false;
   
}

/**
 *Executes a shot from Aaron with strategy 1.
 */ 
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   if (C_alive) {
      if (shoot_target_result <= A_accuracy) {
         C_alive = false;
      }
   }
   else {
      if (shoot_target_result <= A_accuracy) {
         B_alive = false;
      }
   } 
}
 
 /**
  *Executes a shot from Bob.
  */
void Bob_shoots(bool& A_alive, bool& C_alive) {
   if (C_alive) {
      if (shoot_target_result <= B_accuracy) {
         C_alive = false;
      }
   }
   else {
      if (shoot_target_result <= B_accuracy) {
         A_alive = false;
      }
   }
}
 
/**
 *Executes a shot from Charlie.
 */ 
void Charlie_shoots(bool& A_alive, bool& B_alive) {
   if (B_alive) {
      B_alive = false;
   }
   else {
      A_alive = false;
   }
}
 
/**
 *Executes a shot from Aaron with strategy 2.
 */
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   if (C_alive && B_alive) {
      return;
   }
   if (C_alive) {
      if (shoot_target_result <= A_accuracy) {
         C_alive = false;
      }
   }
   else {
      if (shoot_target_result <= A_accuracy) {
         B_alive = false;
      }
   } 
}
 
/**
 *Simple method to implement pause function in linux.
 */ 
void Press_any_key(void) {
   cout << "Press Enter to continue...";
   cin.ignore().get(); 
}

void test_at_least_two_alive(void) {

   bool aaron;
   bool bob;
   bool charlie;
   
   cout << "Unit Testing 1: Function -at_least_two_alive()\n";
   //Test 1
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   aaron = true;
   bob = true;
   charlie = true;
   assert(at_least_two_alive(aaron, bob, charlie) == true);
   cout << "\tCase passed ...\n";
   //Test 2
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   aaron = false;
   bob = true;
   charlie = true;
   assert(at_least_two_alive(aaron, bob, charlie) == true);
   cout << "\tCase passed ...\n";
   //Test 3
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   aaron = true;
   bob = false;
   charlie = true;
   assert(at_least_two_alive(aaron, bob, charlie) == true);
   cout << "\tCase passed ...\n";
   //Test 4
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   aaron = true;
   bob = true;
   charlie = false;
   assert(at_least_two_alive(aaron, bob, charlie) == true);
   cout << "\tCase passed ...\n";
   //Test 5
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   aaron = false;
   bob = false;
   charlie = true;
   assert(at_least_two_alive(aaron, bob, charlie) == false);
   cout << "\tCase passed ...\n";
   //Test 6
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   aaron = false;
   bob = true;
   charlie = false;
   assert(at_least_two_alive(aaron, bob, charlie) == false);
   cout << "\tCase passed ...\n";
   //Test 7
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   aaron = true;
   bob = false;
   charlie = false;
   assert(at_least_two_alive(aaron, bob, charlie) == false);
   cout << "\tCase passed ...\n";
   //Test 8
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   aaron = false;
   bob = false;
   charlie = false;
   assert(at_least_two_alive(aaron, bob, charlie) == false);
   cout << "\tCase passed ...\n";
}

void test_Aaron_shoots1(void) {

   shoot_target_result = 0;
   bool bob;
   bool charlie;
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   //Test 1
   cout << "\tCase 1: Bob alive, Charlie alive\n";
   bob = true;
   charlie = true;
   Aaron_shoots1(bob, charlie);
   assert(charlie == false);
   cout << "\t\tAaron is shooting at Charlie\n";
   //Test 2
   cout << "\tCase 2: Bob dead, Charlie alive\n";
   bob = false;
   charlie = true;
   Aaron_shoots1(bob, charlie);
   assert(charlie == false);
   cout << "\t\tAaron is shooting at Charlie\n";
   //Test 3
   cout << "\tCase 3: Bob alive, Charlie dead\n";
   bob = true;
   charlie = false;
   Aaron_shoots1(bob, charlie);
   assert(bob == false);
   cout << "\t\tAaron is shooting at Bob\n";
}


void test_Bob_shoots(void) {
   
   shoot_target_result = 0;
   bool aaron;
   bool charlie;
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   //Test 1
   cout << "\tCase 1: Aaron alive, Charlie alive\n";
   aaron = true;
   charlie = true;
   Bob_shoots(aaron, charlie);
   assert(charlie == false);
   cout << "\t\tBob is shooting at Charlie\n";
   //Test 2
   cout << "\tCase 2: Aaron dead, Charlie alive\n";
   aaron = false;
   charlie = true;
   Bob_shoots(aaron, charlie);
   assert(charlie == false);
   cout << "\t\tBob is shooting at Charlie\n";
   //Test 3
   cout << "\tCase 3: Aaron alive, Charlie dead\n";
   aaron = true;
   charlie = false;
   Bob_shoots(aaron, charlie);
   assert(aaron == false);
   cout << "\t\tBob is shooting at Aaron\n";
}

void test_Charlie_shoots(void) {

   shoot_target_result = 0;
   bool aaron;
   bool bob;
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
   //Test 1
   cout << "\tCase 1: Aaron alive, Bob alive\n";
   aaron = true;
   bob = true;
   Charlie_shoots(aaron, bob);
   assert(bob == false);
   cout << "\t\tCharlie is shooting at Bob\n";
   //Test 2
   cout << "\tCase 2: Aaron dead, Bob alive\n";
   aaron = false;
   bob = true;
   Charlie_shoots(aaron, bob);
   assert(bob == false);
   cout << "\t\tCharlie is shooting at Bob\n";
   //Test 3
   cout << "\tCase 3: Aaron alive, Bob dead\n";
   aaron = true;
   bob = false;
   Charlie_shoots(aaron, bob);
   assert(aaron == false);
   cout << "\t\tCharlie is shooting at Aaron\n";
}

void test_Aaron_shoots2(void) {
   
   shoot_target_result = 0;
   bool bob;
   bool charlie;
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   //Test 1
   cout << "\tCase 1: Bob alive, Charlie alive\n";
   bob = true;
   charlie = true;
   Aaron_shoots2(bob, charlie);
   assert(bob == true && charlie == true);
   cout << "\t\tAaron intentionally misses his first shot\n";
   cout << "\t\tBoth Bob and Charlie are alive.\n";
   //Test 2
   cout << "\tCase 2: Bob dead, Charlie alive\n";
   bob = false;
   charlie = true;
   Aaron_shoots2(bob, charlie);
   assert(charlie == false);
   cout << "\t\tAaron is shooting at Charlie\n";   
   //Test 3
   cout << "\tCase 3: Bob alive, Charlie dead\n";
   bob = true;
   charlie = false;
   Aaron_shoots2(bob, charlie);
   assert(bob == false);
   cout << "\t\tAaron is shooting at Bob\n";
}
