class Polygon {
public:
  Polygon() : area_(-1) {}

  void AddPoint(const Point& pt) {
    InvalidateArea();
    points_.push_back(pt);
  }

  Point GetPoint(int i) const {
    return points_[i];
  }

  int GetNumPoints() const {
    return points_.size();
  }

  double GetArea() const {
    if( area_ < 0 ) // if not yet calculated and cached
      CalcArea();     // calculate now
    return area_;
    }

private:
  void InvalidateArea() { area_ = -1; }

  void CalcArea() const {
    area_ = 0;
    vector<Point>::const iterator i;
    for( i = points_.begin(); i != points_.end(); ++i )
      area_ += /* some work */;
  }

  vector<Point> points_;
  mutable double        area_;
};

Polygon operator+( const Polygon& lhs, const Polygon& rhs ) {
  Polygon ret = lhs;
  int last = rhs.GetNumPoints();
  for( int i = 0; i < last; ++i ) // concatenate
    ret.AddPoint( rhs.GetPoint(i) );
  return ret;
}

void f( const Polygon& poly ) {
  const_cast<Polygon&>(poly).AddPoint( Point(0,0) );
}

void g( Polygon& const rPoly ) {
  rPoly.AddPoint( Point(1,1) );
}

void h( Polygon* const pPoly ) {
  pPoly->AddPoint( Point(2,2) );
}

int main() {
  Polygon poly;
  const Polygon cpoly;
  f(poly);
  f(cpoly);
  g(poly);
  h(&poly);
}
