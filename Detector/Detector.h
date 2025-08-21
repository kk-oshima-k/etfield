#ifndef DETECTOR_H
#define DETECTOR_H

class Detector{
public:

  virtual ~Detector();

  virtual bool detect() = 0;
};

#endif // DETECTOR_H