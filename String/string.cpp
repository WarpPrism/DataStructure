
String::String (const char *in_string)
/* 
 
Pre:  The pointer in_string references a C-string.
Post: The String is initialized by the C-string in_string.
 
*/
{
   length = strlen(in_string);
   entries = new char[length + 1];
   strcpy(entries, in_string);
}
 
//String::String (List<char> &in_list)
///* 
// 
//Post: The String is initialized by the character List in_list.
// 
//*/
//{
//   length = in_list.size();
//   entries = new char[length + 1];
//   for (int i = 0; i < length; i++) in_list.retrieve(i,entries[i]);
//   entries[length] = '\0';
//}

const char* String::c_str() const
/* 
 
Post: A pointer to a legal C-string object matching
the String is returned.
 
*/
{
   return (const char *) entries;
}
 
String::String(const String &copy)
/* 
 
Post: A new String object is created to match copy.
 
*/
{
   length = strlen(copy.entries);
   entries = new char[length + 1];
   strcpy(entries, copy.entries);
}
 
String::String()
/* 
 
Post: A new empty String object is created.
 
*/
{
   length = 0;
   entries = new char[length + 1];
   strcpy(entries, "");
}
 
String::~String()
/* 
 
Post: The dynamically aquired storage of a String is deleted.
 
*/
{
   delete []entries;
}
 
void String:: operator =(const String &copy)
/* 
 
Post: A String object is assigned the value of the String copy.
 
*/
{
   if (strcmp(entries, copy.entries) != 0) {
      delete []entries;
      length = strlen(copy.entries);
      entries = new char[length + 1];
      strcpy(entries, copy.entries);
   }
}
 
bool operator ==(const String &first, const String &second)
/* 
 
Post: Return true if the String first agrees with
String second.  Else: Return false.
 
*/
{
   return strcmp(first.c_str(), second.c_str()) == 0;
}
 
bool operator >(const String &first, const String &second)
/* 
 
Post: Return true if the String first is lexicographically
later than String second.  Else: Return false.
 
*/
{
   return strcmp(first.c_str(), second.c_str()) > 0;
}
 
bool operator <(const String &first, const String &second)
/* 
 
Post: Return true if the String first is lexicographically
earlier than String second.  Else: Return false.
 
*/
{
   return strcmp(first.c_str(), second.c_str()) < 0;
}
 
bool operator >=(const String &first, const String &second)
/* 
 
Post: Return true if the String first is not lexicographically
earlier than String second.  Else: Return false.
 
*/
{
   return strcmp(first.c_str(), second.c_str()) >= 0;
}
 
bool operator <=(const String &first, const String &second)
/* 
 
Post: Return true if the String first is not lexicographically
later than String second.  Else: Return false.
 
*/
{
   return strcmp(first.c_str(), second.c_str()) <= 0;
}
 
bool operator !=(const String &first, const String &second)
/* 
 
Post: Return true if the String first is not
equal to String second.  Else: Return false.
 
*/
{
   return strcmp(first.c_str(), second.c_str()) != 0;
}
 
int strstr(String s, String t)
/* 
 
Post: Returns the index of the first copy of String 
as a substring of String .  Else: Return -1.
 
*/
{
   int answer;
   const char* content_s = s.c_str();
   char *p = strstr((char *) content_s, t.c_str());
   if (p == NULL) answer = -1;
   else answer = p - content_s;
   return answer;
}
 
String read_in(istream &input, int &terminator)
/* 
 
Post: Return a String read (as characters terminated
by a newline or an end of file character)
from an istream parameter.
The terminating character is recorded
with the output parameter terminator.
 
*/

{
   List<char> temp;
   int size = 0;

   while ((terminator = input.peek()) != EOF &&
          (terminator = input.get()) != '\n')
      temp.insert(size++, terminator);
   String answer(temp);
   return answer;
}
 
String read_in(istream &input)
/* 
 
Post: Return a String read (as characters terminated
by a newline or an end-of-file character)
from an istream parameter.
 
*/
{
   List<char> temp;
   int size = 0;

   char c;
   while ((c = input.peek()) != EOF && (c = input.get()) != '\n')
      temp.insert(size++, c);
   String answer(temp);
   return answer;
}
 
void write(String &s)
/* 
 
Post: The String parameter s is written to cout.
 
*/
{
   cout << s.c_str() << endl;
}
 
void strcpy(String &s, String &t)
/* 
 
Post:
Copies the value of String  to String s.
 
*/
{
   s = t;
}
 
void strncpy(String &s, const String &t, unsigned len)
/* 
 
Post:
Copies the first len characters of String  to make String s.
 
*/
{
   const char *temp = t.c_str();
   char *copy = new char[len + 1];
   strncpy(copy, temp, len);
   copy[len] = 0;
   s = copy;
   delete []copy;
}
 
void strcat(String &add_to, const String &add_on)
/* 
Post: The function concatenates String add_on
onto the end of String add_to.
*/
{
   const char *cfirst = add_to.c_str();
   const char *csecond = add_on.c_str();
   char *copy = new char[strlen(cfirst) + strlen(csecond) + 1];
   strcpy(copy, cfirst);
   strcat(copy, csecond);
   add_to = copy;
   delete []copy;
}
