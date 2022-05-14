



/* Assignment: 2
Author: Roey Salah ID: 206115438
Author: Priel Hoffman ID: 318277308
*/

#include "String.h"

// defult destractor
String::String() : name(nullptr){
}
//this function removing the spaces or tabs
char* String::remove_spaces(char *new_name){
    bool word_found = false;
    char* res = nullptr;//use for return the string after remove the spaces
    int res_index = 0;
    int memoryAmount=to_alloc(new_name);//check how many chars to allocate with to_alloc function
    res = new char[memoryAmount + 1];//+1 allocating for the '\0' at the end
    res[memoryAmount] = '\0';//add '\0' at the end

    for (int i = 0; new_name[i] != '\0'; i++)
    {
        if (new_name[i] != ' ' && new_name[i] != '\t' && new_name[i] != '\n')//check for the first space\tab\endline
        {
            res[res_index] = new_name[i];//put the char in the index it belong
            res_index++;

            if (!isdigit(new_name[i])) {//check if the char not equal to number
                word_found = true;
            }
        }
        else if (word_found && new_name[i + 1] != '\0'){
            res[res_index] = ' '; //add one space between the words
            word_found = false;
            res_index++;
        }
    }
    return res;
}
//this function allocate the number of chars for the string
int String::to_alloc(char* new_name)
{
    int m_aloc = 0; //the number of chars to allocate for the string
    bool word_found = false;

    for (int i = 0; new_name[i] != '\0'; i++)
    {
        if (new_name[i] != ' ' && new_name[i] != '\t' && new_name[i] != '\n')//check for the first space\tab\endline
        {
            m_aloc++;//add space between two words

            if(!isdigit(new_name[i]))//check if the char not equal to number
                word_found = true; //found a char in string
        }
        else if (word_found && new_name[i + 1] != '\0') { //check if the word found and not equal to the end of the string
            m_aloc++;
            word_found = false;
        }
    }
    return m_aloc;
}


//constructor
String::String(char *new_name){
    name = remove_spaces(new_name); //call for removing spaces function
}
// copy constructor
String::String(const String& str) {
    name = new char[strlen(str.name) + 1]; //Dynamic allocation
    strcpy(name, str.name); //making Copy of the string
}
// distractor
String::~String(){
    delete []name; //remove Dynamic allocation
}
//This oprator make assignment of object to another
String &String:: operator=(const String & obj){
    name = new char[strlen(obj.name) + 1]; //Dynamic allocation
    strcpy(name,obj.name); //making Copy of the string
    return *this;
}


//This oprator make Comparison of the objects and return bool value
bool String:: operator==(const String & str){
    return !strcmp(this->name, str.name);
}
//This oprator check if the objects string are equal
bool String::operator!=(const String& str)
{
    return !(*this == str);
}

//getter function of the reference
char* String::getRef()
{
    return this->name;
}

//Output Operator Overloading
ostream& operator<<(ostream& op, const String& str){
    op << str.name;
    return op;
}
//Input Operator Overloading
istream& operator>>(istream& in, String& str){
    char temp[1000]; //max number of chars in the input
    cin.ignore(); //used to ignore or clear one or more characters from the input buffer.
    cin.get(temp, 1000);//reads the string with the whitespace
    //cleaning previous data
    if(str.name!= nullptr)
        delete str.name;

    str.name = str.remove_spaces(temp);

    return in;
}