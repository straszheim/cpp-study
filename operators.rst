list operators, overloadability, and associativity

+------- precedence
|  +---- overloadable
|  | +-- associativity
|  | |     Op 	             Description			  	
           		     
1    L-R   ::		     Scope resolution (C++ only)		
           		     
2  *       x++ x--	     postincrement, postdecrement
   *       ()		     Function call
   *       []		     Array subscripting
           .		     Element selection by reference
   *       ->		     
           typeid()	     Run-time type information
           const_cast	     Type cast (C++ only)
           dynamic_cast	     Type cast (C++ only)
           reinterpret_cast  Type cast (C++ only)
           static_cast	     Type cast (C++ only)
           		     
3  * R-L   ++x --X           preincrement, predecrement
   *       + -		     Unary plus and minus
   *       ! ~		     Logical NOT and bitwise NOT
           (type)	     Type cast
   *       *		     Indirection (dereference)
   *       &		     Address-of
           sizeof	     Size-of
   *       new, new[]	     Dynamic memory allocation 
   *       delete, delete[]  Dynamic memory deallocation
           		     
4    L-R   .*		     
4  *       ->*		     
           		     
5  *       * / %	     Multiplication, division, and mod
           		     
6  *       + -		     Addition and subtraction
           		     
7  *       << >>	     Bitwise left shift and right shift
           		     
8  *       < <= > >=	     relational operators           		     

9  *       == !=	     relational operators	   
           		     
10 *       &		     Bitwise AND
           		     
11 *       ^		     Bitwise XOR (exclusive or)
           		     
12 *       |		     Bitwise OR (inclusive or)
           		     
13 *       &&		     Logical AND
           		     
14 *       ||		     Logical OR
           		     
15   R-L   ?:		     Ternary conditional (see ?:)	
           		     
16 *       =		     Direct assignment
   *       += -=	     	   
   *       *= /= %=	     
   *       <<= >>=	     	   
   *       &= ^= |=	     
           		     
17         throw	     Throw operator
           		     
18 *       ,		     Comma	  	      		
