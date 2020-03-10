/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 steps:
 
 0) press the Compile, link and run... button and work your way through all of the error messages.
         you can click on them to be taken to the appropriate line number.
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses bigger's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T  // Declaring a Class of objects that contains a value and a name2
{
    char value;
    std::string name;

    T(char v, const char* myName)   //1     was thrown off by the const char*
    {
        value = v; //2
        name = myName; //3
    }
};

struct Compare                                //4  A class of objects that can compare objects of type T
{
    T* compare(T* a, T* b) //5  Comparing the member variable inside the T objects and returning the smaller one, but with pointers instead of copying.  Arguments should be addresses
    {
        if ( a != nullptr && b != nullptr )
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float val1 { 0 }, val2 { 0 };
    float multiply(float* uVal)      //12
    {
        if( uVal != nullptr )
        {
            std::cout << "U's val1 value: " << val1 << std::endl;
            val1 = *uVal;
            std::cout << "U's val1 updated value: " << val1 << std::endl;

            while ( std::abs( val2 - val1 ) > 0.001f )
            {
                if( std::abs( val2 ) > std::abs( val1) )
                {
                    ++val1;
                }
                else
                {
                    ++val2;
                }
            }

            std::cout << "U's val2 updated value: " << val2 << std::endl;

            return val2 * val1;
        }

        std::cout << "Error, arguments return nullptr.\n";    
        return val1;
    }
};

struct StaticStuff
{
    static float staticMultiply(U* that, float* newVal )        //10
    {
        if( that != nullptr && newVal != nullptr)
        {
            std::cout << "U's val1 value: " << that->val1 << std::endl;
            that->val1 = *newVal;
            std::cout << "U's val1 updated value: " << that->val1 << std::endl;

            while( std::abs(that->val2 - that->val1) > 0.001f )
            {
                if( std::abs( that->val2 ) > std::abs(that->val1) )
                {
                    ++that->val1;
                }
                else                                                                           
                {
                    ++that->val2;
                }
            }
            std::cout << "U's val2 updated value: " << that->val2 << std::endl;
            return that->val2 * that->val1;
        }

        std::cout << "Error, arguments return nullptr.\n";    
        return that->val2;
    }
};

int main()
{
    T a( 'b', "A" );                                             //6
    T b( 'f', "B" );                                             //6
    
    Compare f;                                            //7
    auto* smaller = f.compare( &a, &b );                              //8

    if( smaller != nullptr )
    std::cout << "the smaller one is << " << smaller->name << std::endl; //9

    U first;
    float updatedValue = 5.f;

    float productFirst = StaticStuff::staticMultiply( &first, &updatedValue);
    std::cout << "[static func] First's multiplied values: " << productFirst << std::endl;                  //11
     
    U second;

    float productSecond = second.multiply( &updatedValue );
    std::cout << "[member func] Second's multiplied values: " << productSecond << std::endl;
 }

        
        
        
        
        
        
        
