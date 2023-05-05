#include <iostream>
#include <cmath>
#include <cstdlib>

struct FigureParams {
  double param1;
  double param2;
  double param3;
};

double CalcCircleArea(double radius) {
  return 3.14 * radius * radius;
}

double CalcTriangleArea(double a, double b, double c) {
  double p = (a + b + c) / 2.0;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main(int argc, char** argv) {
  if (argc == 1 or argc == 2) {
  std::cout << "Usage ./calculator -o <Figur_type> <params>" << std::endl;
  std::cout << "Supported figure types: circle, triangle" << std::endl;
  std::cout << "Params for circle: <radius>" << std::endl;
  std::cout << "Params for triangle: <a> <b> <c>" << std::endl;
  return 0;
  }
  
  std::string figureType = argv[2];
  
  FigureParams params;
  if (figureType == "circle") {
    if (argc != 4) {
      std::cout << "Error: invalid number of arguments" << std::endl;
      return 1;
    }
    params.param1 = atof(argv[3]);
    
    double area = CalcCircleArea(params.param1);
    std::cout << "Circle area: " << area << std::endl;
    
  } else if (figureType == "triangle") {
    if (argc != 6) {
      std::cout << "Error: invalid number of arguments" << std::endl;
      return 1;
    }
    params.param1 = atof(argv[3]);
    params.param2 = atof(argv[4]);
    params.param3 = atof(argv[5]);
    
    double area = CalcTriangleArea(params.param1, params.param2, params.param3);
    std::cout << "Triangle area: " << area << std::endl;
    
  } else {
    std::cout << "Error: unsupported figure type" << std::endl;
    return 1;
  }
  
  return 0;
}
  
  
