
class UnaryFunction {
public:
  virtual ~UnaryFunction() {}
  virtual double value(double x) const = 0;
  virtual UnaryFunction* derivative() const = 0;
  virtual UnaryFunction* clone() const = 0;
};

