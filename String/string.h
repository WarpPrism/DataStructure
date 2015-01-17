#ifndef STRING_H
#define STRING_H

class String {
public:                           //  methods of the string ADT
   String();
   ~String();
   String (const String &copy);   //  copy constructor
   String (const char * copy);    //  conversion from C-string
   // String (List<char> &copy);     //  conversion from List 

   void operator =(const String &copy);
   const char *c_str() const;     //  conversion to C-style string

protected:
 
   char *entries;
   int length;
};
 
bool operator ==(const String &first, const String &second);
bool operator >(const String &first, const String &second);
bool operator <(const String &first, const String &second);
bool operator >=(const String &first, const String &second);
bool operator <=(const String &first, const String &second);
bool operator !=(const String &first, const String &second);

#endif
