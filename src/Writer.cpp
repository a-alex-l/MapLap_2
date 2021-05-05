#include "Writer.h"

#include <fstream>

void Writer::write(int image_width,
                   int image_height,
                   const std::string &file_name,
                   const std::vector<Line> &lines,
                   const std::vector<Ellipse> &ellipses) {
    std::ofstream output_file;
    output_file.open(file_name);
    if (!output_file.is_open())
        throw std::ios_base::failure("Error: wrong file name. Can't open file " + file_name);
    output_file << "\\documentclass{article}\n"
                   "\n"
                   "\\usepackage{geometry} \\geometry{verbose,a4paper,tmargin=0.5cm,bmargin=0.5cm,lmargin=0.5cm,rmargin=0.5cm}\n"
                   "\\usepackage{tikz}\n"
                   "\\newcommand{\\MapLapImage} [1] {\n"
                   "    \\begin{tikzpicture} [scale = #1, yscale = -1]\n"
                   "        \\newcommand{\\ImageWidth} {" << image_width << "mm}\n"
                   "        \\newcommand{\\ImageHeight} {" << image_height << "mm}\n"
                   "        \\draw (0, 0)\n"
                   "            rectangle (\\ImageWidth, \\ImageHeight);\n"
                   "            \n";

    for (const auto &line : lines)
        output_file << "        " << line << "\n";

    for (const auto &ellipse : ellipses)
        output_file << "        " << ellipse << "\n";

    output_file << "    \\end{tikzpicture}}\n"
                   "\n"
                   "\\begin{document}\n"
                   "\n"
                   "    Copy before begining of the document lines 3 to 11.\\\\\n"
                   "    \n"
                   "    Insert line next line wherever you want this picture.\\\\\n"
                   "    \n"
                   "    \\MapLapImage{" << 160.0 / image_width << "}\n"
                   "    \n"
                   "    Using parameter you can change scale of the image.\n"
                   "        \n"
                   "\n"
                   "\\end{document} ";


    output_file.close();
}
