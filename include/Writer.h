#ifndef MAPLAP2_0_WRITER_H
#define MAPLAP2_0_WRITER_H

#include "shapes/Line.hpp"
#include "shapes/Ellipse.hpp"

namespace Writer {

    void write(int image_width,
               int image_height,
               const std::string &file_name,
               const std::vector<Line> &lines,
               const std::vector<Ellipse> &ellipses);

}



#endif //MAPLAP2_0_WRITER_H
