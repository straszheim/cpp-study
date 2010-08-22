/*

 * they just add extra checking to the code, unless the compiler can
 prove that the spec can never be violated, in which case it can
 throw the checking code out

 * when they're violated they immediatedly terminate the program

 * you can't really write them for function templates, you don't know
 what the types will throw

 
 they're touchy:

 * illegal for typedef of pointer to function

 * legal for same w/o typedef

 * required for virtual function that overrides function that has spec
 already

 * implicit and automatic for implicitly generated constructors,
 assignment operators, destructors

*/




















 */
