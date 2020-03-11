/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T  // Declaring a Class of objects that contains a value and a name2
{
    char value;
    std::string name;

    T(char v, const char* myName)   //1
    {
        value = v; //2
        name = myName; //3
    }
};

struct Compare                                //4  A class of objects that can compare objects of type T
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        std::cout << "The values are the same.\n";
        return nullptr;
    }
};

struct U
{
    float val1 { 0 }, val2 { 0 };
    float multiply(float& uVal)      //12
    {
        std::cout << "U's val1 value: " << val1 << std::endl;
        val1 = uVal;
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
};

struct StaticStuff
{
    static float staticMultiply(U& that, float& newVal )        //10
    {
        std::cout << "U's val1 value: " << that.val1 << std::endl;
        that.val1 = newVal;
        std::cout << "U's val1 updated value: " << that.val1 << std::endl;

        while( std::abs(that.val2 - that.val1) > 0.001f )
        {
            if( std::abs( that.val2 ) > std::abs(that.val1) )
            {
                ++that.val1;
            }
            else                                                                           
            {
                ++that.val2;
            }
        }
        std::cout << "U's val2 updated value: " << that.val2 << std::endl;
        return that.val2 * that.val1;
    }
};

int main()
{
    T a( 'b', "A" );                                             //6
    T b( 'f', "B" );                                             //6
    
    Compare f;                                            //7
    auto* smaller = f.compare( a, b );                              //8

    if( smaller != nullptr )
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9

    U first;
    float updatedValue = 5.f;

    float productFirst = StaticStuff::staticMultiply( first, updatedValue);
    std::cout << "[static func] First's multiplied values: " << productFirst << std::endl;                  //11
     
    U second;

    float productSecond = second.multiply( updatedValue );
    std::cout << "[member func] Second's multiplied values: " << productSecond << std::endl;
 }

        
        
        
        
        
        
        
