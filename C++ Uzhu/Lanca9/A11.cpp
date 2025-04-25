#include <iostream>

double SlantMult(double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
}

bool SectionSegments(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    bool b;
    double xmax1, xmax2, xmin1, xmin2, ymax1, ymax2, ymin1, ymin2;
    double acx, acy, abx, aby, adx, ady, cax, cay, cbx, cby, cdx, cdy;

    if (x1 > x2) {
        xmax1 = x1;
        xmin1 = x2;
    } else {
        xmax1 = x2;
        xmin1 = x1;
    }

    if (x3 > x4) {
        xmax2 = x3;
        xmin2 = x4;
    } else {
        xmax2 = x4;
        xmin2 = x3;
    }

    if (y1 > y2) {
        ymax1 = y1;
        ymin1 = y2;
    } else {
        ymax1 = y2;
        ymin1 = y1;
    }

    if (y3 > y4) {
        ymax2 = y3;
        ymin2 = y4;
    } else {
        ymax2 = y4;
        ymin2 = y3;
    }

    if (xmax1 >= xmin2 && xmax2 >= xmin1 && ymax1 >= ymin2 && ymax2 >= ymin1) {
        acx = x3 - x1;
        acy = y3 - y1;
        abx = x2 - x1;
        aby = y2 - y1;
        adx = x4 - x1;
        ady = y4 - y1;
        cax = x1 - x3;
        cay = y1 - y3;
        cbx = x2 - x3;
        cby = y2 - y3;
        cdx = x4 - x3;
        cdy = y4 - y3;
        
        b = (SlantMult(acx, acy, abx, aby) * SlantMult(adx, ady, abx, aby) <= 0) &&
            (SlantMult(cax, cay, cdx, cdy) * SlantMult(cbx, cby, cdx, cdy) <= 0);

        return b;
    } else {
        return false;
    }
}

int main() {
    double xx1, yy1, xx2, yy2, xx3, yy3, xx4, yy4;
    std::cin >> xx1 >> yy1 >> xx2 >> yy2 >> xx3 >> yy3 >> xx4 >> yy4;

    if (SectionSegments(xx1, yy1, xx2, yy2, xx3, yy3, xx4, yy4)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
