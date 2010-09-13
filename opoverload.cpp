// || &&
// these won't short-circuit like they do when they're not overloaded:

T operator||(T& lhs, T& rhs);
// it gets evaluated like a function

// , comma operator is always evaluated left-to-right, but when
// overloaded there are function call semantics: you don't know what
// order arguments are evaluated in







