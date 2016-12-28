#pragma once

class C {
public:
  explicit C(std::string n);
  ~C();

  C(const C&);
  C(C&&);

  C& operator=(const C&);
  C& operator=(C&&);

  static int constructions;
  static int destructions;
  static int moveconstructs;
  static int copies;
  static int copyassigns;
  static int moveassigns;
  static int population;
  void report(const char* file, int line, const char* name);

  std::string name;

};

#define REPORT(OBJ) OBJ.report(__FILE__, __LINE__, BOOST_PP_STRINGIZE(OBJ));
