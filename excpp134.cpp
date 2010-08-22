
struct B
{
  int f(int);
  int f(double);

  int g(int);
};

struct D : B 
{
private:
  int g(std::string, bool);
};

int main(int, char**)
{
  D d;
  int i;
  d.f(i);
  d.g(i);
}

// what is happening and why does it work this way?

