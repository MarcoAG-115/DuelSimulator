//  Marco Gonzalez
//  mag0089
//  project2_mag0089.cpp
//  Project_2
//
//  I used the lecture notes (01/27/20) for
//  help on decimal formatting and generating
//  random numbers.
//
//  I used the given project examples from the
//  project pdf and pseudo code packet in order
//  to create my functions and tests.
//
//  I used stackoverflow.com to learn how to
//  improve my random number generator. Also
//  I searched how to make constants.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

/*Constants*/

const int Number_of_trials = 10000;
const int Aarons_chance = 33;
const int Bobs_chance = 50;

/*Functions*/

//Returns true if at least two people live,
//otherwise the output is false.
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive)
{
    if ((A_alive == true) && (B_alive == true) && (C_alive == true))
    {
        return true;
    }
    if ((A_alive == false) && (B_alive == true) && (C_alive == true))
    {
        return true;
    }
    if ((A_alive == true) && (B_alive == false) && (C_alive == true))
    {
        return true;
    }
    if ((A_alive == true) && (B_alive == true) && (C_alive == false))
    {
        return true;
    }
    return false;
    
}

//Changes B_alive to false if Bob dies,
//or changes C_alive to false if Charlie dies.
void Aaron_shoots1(bool& B_alive, bool& C_alive)
{
    int Aaron_shooting_results;
    
    if ((B_alive == true) && (C_alive == true))
    {
        
        Aaron_shooting_results = rand()%100;
        
        if (Aaron_shooting_results <= Aarons_chance)
        {
            C_alive = false;
        }
        
    }
    else if ((B_alive == true) && (C_alive == false))
    {
        
        Aaron_shooting_results = rand()%100;
        
        if (Aaron_shooting_results <= Aarons_chance)
        {
            B_alive = false;
        }
        
    }
    else if ((B_alive == false) && (C_alive == true))
    {
       
        Aaron_shooting_results = rand()%100;
        
        if (Aaron_shooting_results <= Aarons_chance)
        {
            C_alive = false;
        }
        
    }
    
}

//Changes A_alive to false if Aaron dies,
//or changes C_alive to false if Charlie dies.
void Bob_shoots(bool& A_alive, bool& C_alive)
{
    int Bob_shooting_results;
    
    if ((A_alive == true) && (C_alive == true))
    {
        Bob_shooting_results = rand()%100;
        
        if (Bob_shooting_results <= Bobs_chance)
        {
            C_alive = false;
        }
        
    }
    else if ((A_alive == true) && (C_alive == false))
    {
       Bob_shooting_results = rand()%100;
        
        if (Bob_shooting_results <= Bobs_chance)
        {
            A_alive = false;
        }
        
    }
    else if ((A_alive == false) && (C_alive == true))
    {
       Bob_shooting_results = rand()%100;
        
        if (Bob_shooting_results <= Bobs_chance)
        {
            C_alive = false;
        }
        
    }
    
}

//Changes A_alive to false if Aaron dies,
//or changes B_alive to false if Bob dies.
void Charlie_shoots(bool& A_alive, bool& B_alive)
{
    
    if ((A_alive == true) && (B_alive == true))
    {
        B_alive = false;
        
    }
    else if ((A_alive == true) && (B_alive == false))
    {
        A_alive = false;
        
    }
    else if ((A_alive == false) && (B_alive == true))
    {
        B_alive = false;
        
    }
    
}

//Changes B_alive to false if Bob dies,
//or changes C_alive to false if Charlie dies.
void Aaron_shoots2(bool& B_alive, bool& C_alive)
{
    int Aaron2_shooting_results;
    
    if ((B_alive == true) && (C_alive == false))
    {
        Aaron2_shooting_results = rand()%100;
        
        if (Aaron2_shooting_results <= Aarons_chance)
        {
            B_alive = false;
        }
        
    }
    else if ((B_alive == false) && (C_alive == true))
    {
       Aaron2_shooting_results = rand()%100;
        
        if (Aaron2_shooting_results <= Aarons_chance)
        {
            C_alive = false;
        }
        
    }
    
}

//Tells the user to press the "Enter" key to continue.
void press_key()
{
   cout << "Press any key to continue...";
    cin.ignore();
    
}

/*Unit Tests*/

//at_least_two_alive Test
void test_at_least_two_alive(void)
{
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";
    
    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "\tCase passed ...\n";
    
}

//Aaron_shoots1 Test
void test_Aaron_shoots1(void)
{
    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    
    cout << "\tCase 1: Bob alive, Charlie alive\n";
    bool B_alive = true;
    bool C_alive = true;
    Aaron_shoots1(B_alive, C_alive);
    assert((B_alive == true) && (false == C_alive) || (true == C_alive));
    cout << "\t\tAaron is shooting at Charlie\n";
    
    cout << "\tCase 2: Bob dead, Charlie alive\n";
    B_alive = false;
    C_alive = true;
    Aaron_shoots1(B_alive, C_alive);
    assert((B_alive == false) && (false == C_alive) || (true == C_alive));
    cout << "\t\tAaron is shooting at Charlie\n";
    
    cout << "\tCase 3: Bob alive, Charlie dead\n";
    B_alive = true;
    C_alive = false;
    Aaron_shoots1(B_alive, C_alive);
    assert((C_alive == false) && (false == B_alive) || (true == B_alive));
    cout << "\t\tAaron is shooting at Bob\n";
    
}

//Bob_shoots Test
void test_Bob_shoots(void)
{
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
    
    cout << "\tCase 1: Aaron alive, Charlie alive\n";
    bool A_alive = true;
    bool C_alive = true;
    Bob_shoots(A_alive, C_alive);
    assert((A_alive == true) && (false == C_alive) || (true == C_alive));
    cout << "\t\tBob is shooting at Charlie\n";
    
    cout << "\tCase 2: Aaron dead, Charlie alive\n";
    A_alive = false;
    C_alive = true;
    Bob_shoots(A_alive, C_alive);
    assert((A_alive == false) && (false == C_alive) || (true == C_alive));
    cout << "\t\tBob is shooting at Charlie\n";
    
    cout << "\tCase 3: Aaron alive, Charlie dead\n";
    A_alive = true;
    C_alive = false;
    Bob_shoots(A_alive, C_alive);
    assert((C_alive == false) && (false == A_alive) || (true == A_alive));
    cout << "\t\tBob is shooting at Aaron\n";
    
}

//Charlie_shoots Test
void test_Charlie_shoots(void)
{
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
    
    cout << "\tCase 1: Aaron alive, Bob alive\n";
    bool A_alive = true;
    bool B_alive = true;
    Charlie_shoots(A_alive, B_alive);
    assert(false == B_alive);
    cout << "\t\tCharlie is shooting at Bob\n";
    
    cout << "\tCase 2: Aaron dead, Bob alive\n";
    A_alive = false;
    B_alive = true;
    Charlie_shoots(A_alive, B_alive);
    assert(false == B_alive);
    cout << "\t\tCharlie is shooting at Bob\n";
    
    cout << "\tCase 3: Aaron alive, Bob dead\n";
    A_alive = true;
    B_alive = false;
    Charlie_shoots(A_alive, B_alive);
    assert(false == A_alive);
    cout << "\t\tCharlie is shooting at Aaron\n";
    
}

//Aaron_shoots2 Test
void test_Aaron_shoots2(void)
{
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    
    cout << "\tCase 1: Bob alive, Charlie alive\n";
    bool B_alive = true;
    bool C_alive = true;
    Aaron_shoots2(B_alive, C_alive);
    assert((true == B_alive) && (true == C_alive));
    cout << "\t\tAaron intentionally misses his first shot\n";
    cout << "\t\tBoth Bob and Charlie are alive.\n";
    
    cout << "\tCase 2: Bob dead, Charlie alive\n";
    B_alive = false;
    C_alive = true;
    Aaron_shoots2(B_alive, C_alive);
    assert((false == C_alive) || (true == C_alive));
    cout << "\t\tAaron is shooting at Charlie\n";
    
    cout << "\tCase 3: Bob alive, Charlie dead\n";
    B_alive = true;
    C_alive = false;
    Aaron_shoots2(B_alive, C_alive);
    assert((false == B_alive) || (true == B_alive));
    cout << "\t\tAaron is shooting at Bob\n";
    
}


/*Main Function*/
int main()
{
    // Variables
    bool A_alive = true;
    bool B_alive = true;
    bool C_alive = true;
    double Aaron_win_count = 0;
    double Bob_win_count = 0;
    double Charlie_win_count = 0;
    double Aaron_win_count_strat2 = 0;
    double Bob_win_count_strat2 = 0;
    double Charlie_win_count_strat2 = 0;
    int trial_count = 0;
    double A_percentage_strat1 = 0;
    double B_percentage_strat1 = 0;
    double C_percentage_strat1 = 0;
    double A_percentage_strat2 = 0;
    double B_percentage_strat2 = 0;
    double C_percentage_strat2 = 0;
    
    //Initialize random number generator
    srand((unsigned)time(NULL));
    
    //Output
    cout << "*** Welcome to Marco's Duel Simulator ***\n";
    
    test_at_least_two_alive();
    press_key();
    cout << "\n";
    
    test_Aaron_shoots1();
    press_key();
    cout << "\n";
    
    test_Bob_shoots();
    press_key();
    cout << "\n";
    
    test_Charlie_shoots();
    press_key();
    cout << "\n";
    
    test_Aaron_shoots2();
    press_key();
    cout << "\n";
    
    cout << "Ready to test strategy 1 (run 10000 times):\n";
    press_key();
    cout << "\n";
    
    //Strategy 1
    //Calculates how many times each person will win from
    //10,000 trials. (No turns are skipped)
    
    while (trial_count < Number_of_trials)
    {
       
        //Everyone starts alive
        A_alive = true;
        B_alive = true;
        C_alive = true;
        
        //Aaron shoots at Charlie
        //B_alive = true;
        //C_alive = true;
        Aaron_shoots1(B_alive, C_alive);
        
        //Aaron does not kill Charlie
        if ((at_least_two_alive(A_alive, B_alive, C_alive)) && (C_alive == true))
        {
           
            //Bob shoots at Charlie
            //A_alive = true;
            //C_alive = true;
            Bob_shoots(A_alive, C_alive);
            
            //Bob misses
            if ((at_least_two_alive(A_alive, B_alive, C_alive)) && (C_alive == true))
            {
               
                //Charlie shoots and kills Bob
                //A_alive = true;
                //B_alive = true;
                Charlie_shoots(A_alive, B_alive);
                
                //Aaron shoots at Charlie
                //B_alive = false;
                //C_alive = true;
                Aaron_shoots1(B_alive, C_alive);
                
                //Aaron misses
                if ((at_least_two_alive(A_alive, B_alive, C_alive)) && (C_alive == true))
                {
                    //Charlie shoots and kills Aaron
                    //Charlie wins
                    Charlie_win_count++;
                    trial_count++;
                }
                //Aaron kills Charlie
                else
                {
                    //Aaron wins
                    Aaron_win_count++;
                    trial_count++;
                }
            }
            
            //Bob kills Charlie
            else
            {
                //Aaron shoots at Bob
                //B_alive = true;
                //C_alive = false;
                Aaron_shoots1(B_alive, C_alive);
                
                //Aaron misses
                if ((at_least_two_alive(A_alive, B_alive, C_alive)) && (B_alive == true))
                {
                    //Bob shoots at Aaron
                    //A_alive = true;
                    //C_alive = false;
                    Bob_shoots(A_alive, C_alive);
                    
                    //Bob misses
                    if ((at_least_two_alive(A_alive, B_alive, C_alive)) && (A_alive == true))
                    {
                        //Aaron shoots at Bob
                        //B_alive = true;
                        //C_alive = false;
                        Aaron_shoots1(B_alive, C_alive);
                        
                        //Aaron misses
                        if ((at_least_two_alive(A_alive, B_alive, C_alive)) && (B_alive == true))
                        {
                            //Bob shoots and kills Aaron
                            //Bob wins
                            Bob_win_count++;
                            trial_count++;
                        }
                        //Aaron kills Bob
                        else
                        {
                            //Aaron wins
                            Aaron_win_count++;
                            trial_count++;
                        }
                    }
                    //Bob kills Aaron
                    else
                    {
                        //Bob wins
                        Bob_win_count++;
                        trial_count++;
                    }
                }
                //Aaron kills Bob
                else
                {
                    //Aaron wins
                    Aaron_win_count++;
                    trial_count++;
                }
                
            }
            
        }
        
        //Aaron kills Charlie
        else
        {
            //Bob shoots at Aaron
            //A_alive = true;
            //C_alive = false;
            Bob_shoots(A_alive, C_alive);
            
            //Bob misses
            if ((at_least_two_alive(A_alive, B_alive, C_alive)) && (A_alive == true))
            {
                //Aaron shoots at Bob
                //B_alive = true;
                //C_alive = false;
                Aaron_shoots1(B_alive, C_alive);
                
                //Aaron kills Bob
                if ((!(at_least_two_alive(A_alive, B_alive, C_alive))) && (B_alive == false))
                {
                    Aaron_win_count++;
                    trial_count++;
                }
                
                //Aaron misses Bob
                else
                {
                    //Bob shoots at Aaron
                    Bob_win_count++;
                    trial_count++;
                    
                }
            }
            
            //Bob kills Aaron
            else
            {
                //Bob wins
                Bob_win_count++;
                trial_count++;
                
            }
        }
        
    }
    
    //Calculates percentage of duels won from 10,000 (Strategy 1)
    A_percentage_strat1 = (Aaron_win_count / Number_of_trials)*100;
    B_percentage_strat1 = (Bob_win_count / Number_of_trials)*100;
    C_percentage_strat1 = (Charlie_win_count / Number_of_trials)*100;
    
    //Displays duel results using strategy 1
    cout << setprecision(4) << noshowpoint << "Aaron won " << Aaron_win_count << "/10000 duels or ";
    cout << setprecision(2) << fixed << A_percentage_strat1 << "%\n";
    cout << setprecision(0) << noshowpoint << "Bob won " << Bob_win_count << "/10000 duels or ";
    cout << setprecision(2) << fixed << B_percentage_strat1 << "%\n";
    cout << setprecision(0) << noshowpoint << "Charlie won " << Charlie_win_count << "/10000 duels or ";
    cout << setprecision(2) << fixed << C_percentage_strat1 << "%\n\n";
    
    //Prompts user to continue for strategy 2 results
    cout << "Ready to test strategy 2 (run 10000 times):\n";
    press_key();
    cout << "\n";
    
    //Resets trial_count
    trial_count = 0;
    
    //Strategy 2
    //Calculates how many times each person will win from
    //10,000 trials. (Aaron skips his first turn)
    while (trial_count < Number_of_trials)
    {
        //Everyone starts alive
        bool A_alive = true;
        bool B_alive = true;
        bool C_alive = true;
        
        //Bob shoots at Charlie
        //A_alive = true
        //C_alive = true
        Bob_shoots(A_alive, C_alive);
        
        //Bob misses
        if ((at_least_two_alive(A_alive, B_alive, C_alive)) && (C_alive == true))
        {
            //Charlie shoots and kills Bob
            //A_alive = true
            //B_alive = true
            Charlie_shoots(A_alive, B_alive);
            
            //Aaron shoots at Charlie
            //B_alive = false
            //C_alive = true
            Aaron_shoots2(B_alive, C_alive);
            
            //Aaron misses
            if ((at_least_two_alive(A_alive, B_alive, C_alive)) && (C_alive == true))
            {
                //Charlie shoots and kills Aaron
                //Charlie wins
                Charlie_win_count_strat2++;
                trial_count++;
            }
            //Aaron kills Charlie
            else
            {
                //Aaron wins
                Aaron_win_count_strat2++;
                trial_count++;
            }
        }
        //Bob kills Charlie
        else
        {
            //Aaron shoots at Bob
            //B_alive = true
            //C_alive = false
            Aaron_shoots2(B_alive, C_alive);
            
            //Aaron misses
            if ((at_least_two_alive(A_alive, B_alive, C_alive)) && (B_alive == true))
            {
                //Bob shoots at Aaron
                //A_alive = true
                //C_alive = false
                Bob_shoots(A_alive, C_alive);
                
                //Bob misses
                if ((at_least_two_alive(A_alive, B_alive, C_alive)) && (A_alive == true))
                {
                    //Aaron shoots at Bob
                    //B_alive = true
                    //C_alive = false
                    Aaron_shoots2(B_alive, C_alive);
                    
                    //Aaron misses
                    if ((at_least_two_alive(A_alive, B_alive, C_alive)) && (B_alive == true))
                    {
                        //Bob shoots and kills Aaron
                        //Bob wins
                        Bob_win_count_strat2++;
                        trial_count++;
                    }
                    
                    //Aaron kills Bob
                    else
                    {
                        //Aaron wins
                        Aaron_win_count_strat2++;
                        trial_count++;
                    }
                }
                
                //Bob kills Aaron
                else
                {
                    //Bob wins
                    Bob_win_count_strat2++;
                    trial_count++;
                }
            }
            //Aaron kills Bob
            else
            {
                //Aaron wins
                Aaron_win_count_strat2++;
                trial_count++;
            }
        }
    }
    
    //Calculates percentage of duels won from 10,000 (Strategy 2)
    A_percentage_strat2 = (Aaron_win_count_strat2 / Number_of_trials)*100;
    B_percentage_strat2 = (Bob_win_count_strat2 / Number_of_trials)*100;
    C_percentage_strat2 = (Charlie_win_count_strat2 / Number_of_trials)*100;
    
    //Displays duel results using strategy 2
    cout << setprecision(0) << noshowpoint << "Aaron won " << Aaron_win_count_strat2 << "/10000 duels or ";
    cout << setprecision(2) << fixed << A_percentage_strat2 << "%\n";
    cout << setprecision(0) << noshowpoint << "Bob won " << Bob_win_count_strat2 << "/10000 duels or ";
    cout << setprecision(2) << fixed << B_percentage_strat2 << "%\n";
    cout << setprecision(0) << noshowpoint << "Charlie won " << Charlie_win_count_strat2 << "/10000 duels or ";
    cout << setprecision(2) << fixed << C_percentage_strat2 << "%\n\n";
    
    //Determines and outputs which strategy is best for Aaron
    if (Aaron_win_count_strat2 > Aaron_win_count)
    {
        cout << "Strategy 2 is better than strategy 1.\n";
    }
    else
    {
        cout << "Strategy 1 is better than strategy 2.\n";
    }
    return 0;
}
