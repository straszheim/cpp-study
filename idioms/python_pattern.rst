given arbirary functions R(T1, T2, ... TN) i want to call them with
a std::vector<boost::any>

interface:

std::string foo(std::string, unsigned);

callable* c = def(foo);
vector<any> va;
va.push_back(std::string("hi"));
va.push_back(3);

any rv = (*c)(va);


