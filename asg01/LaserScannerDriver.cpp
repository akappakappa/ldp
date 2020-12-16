/**
 * @file LaserScannerDriver.cpp
 * @author Andrea Valentinuzzi matr1219617
 * @brief Implementation of the LaserScannerDriver class.
 * @date 2020-11-26
 * 
 * @see LaserScannerDriver
 */

#include <cmath>
#include "LaserScannerDriver.hpp"

LaserScannerDriver::LaserScannerDriver(double r)
{
    // base check
    if (r < 0.1 || r > 1)
        throw std::invalid_argument("** Resolution must be between 0.1 and 1 **");

    // assignments & initializations
    resolution = r;
    buffer = new double*[BUFFER_DIM]{nullptr};
    buffer_size = 0;
    readings_number = (int)(180 / resolution) + 1;
}

LaserScannerDriver::LaserScannerDriver(const LaserScannerDriver &other)
{
    // base check
    if (this != &other)
    {
        // assignments & initializations
        resolution = other.resolution;
        buffer_size = other.buffer_size;
        readings_number = other.readings_number;
        buffer = new double*[BUFFER_DIM]{nullptr};

        // copy
        for (int i = 0; i < buffer_size; i++)
        {
            buffer[i] = new double[readings_number];
            for (int j = 0; j < readings_number; j++)
                buffer[i][j] = other.buffer[i][j];
        }
    }
    else
    {
        // default constructor
        resolution = 1;
        buffer = new double*[BUFFER_DIM]{nullptr};
        buffer_size = 0;
        readings_number = (int)(180 / resolution) + 1;
    }
}

LaserScannerDriver::LaserScannerDriver(LaserScannerDriver &&other)
{
    // base check
    if (this != &other)
    {
        // assignments & buffer pointer
        resolution = other.resolution;
        buffer_size = other.buffer_size;
        readings_number = other.readings_number;
        buffer = other.buffer;

        // invalidation
        other.buffer_size = 0;
        other.readings_number = 0;
        other.buffer = nullptr;
    }
    else
    {
        // default constructor
        resolution = 1;
        buffer = new double*[BUFFER_DIM]{nullptr};
        buffer_size = 0;
        readings_number = (int)(180 / resolution) + 1;
    }
}

LaserScannerDriver &LaserScannerDriver::operator=(const LaserScannerDriver &other)
{
    // base check
    if (this != &other)
    {
        // deletion
        clear_buffer();

        // assignments & initializations
        resolution = other.resolution;
        buffer_size = other.buffer_size;
        readings_number = other.readings_number;

        // copy
        for (int i = 0; i < buffer_size; i++)
        {
            buffer[i] = new double[readings_number];
            for (int j = 0; j < readings_number; j++)
                buffer[i][j] = other.buffer[i][j];
        }
    }

    return *this;
}

LaserScannerDriver &LaserScannerDriver::operator=(LaserScannerDriver &&other)
{
    // base check
    if (this != &other)
    {
        // deletion
        clear_buffer();
        delete[] buffer;

        // assignments & buffer pointer
        resolution = other.resolution;
        buffer_size = other.buffer_size;
        readings_number = other.readings_number;
        buffer = other.buffer;

        // invalidation
        other.resolution = 0;
        other.buffer_size = 0;
        other.readings_number = 0;
        other.buffer = nullptr;
    }

    return *this;
}

LaserScannerDriver::~LaserScannerDriver()
{
    // invalidation
    resolution = 0;
    readings_number = 0;

    // deletion
    clear_buffer();
    delete[] buffer;
    buffer = nullptr;
}

void LaserScannerDriver::new_scan(const std::vector<double> &v)
{
    // base check
    for (int i = 0; i < v.size() && i < readings_number; i++)
        if (v.at(i) < 0)
            throw std::invalid_argument("** One or more elements of the vector are invalid **");

    // buffer full -> delete first & shift
    if (buffer_size == BUFFER_DIM)
    {
        delete[] buffer[0];
        for (int i = 1; i < buffer_size; i++)
            buffer[i - 1] = buffer[i];
        buffer[--buffer_size] = nullptr;
    }

    // insertion
    buffer[buffer_size] = new double[readings_number];
    for (int i = 0; i < v.size() && i < readings_number; i++)
        buffer[buffer_size][i] = v.at(i);
    for (int i = v.size(); i < readings_number; i++)
        buffer[buffer_size][i] = 0;
    buffer_size++;
}

std::vector<double> LaserScannerDriver::get_scan()
{
    // base check
    if (!buffer_size)
        throw std::length_error("** Buffer is empty **");
    
    // saving vector
    std::vector<double> ret(readings_number);
    for (int i = 0; i < readings_number; i++)
        ret.at(i) = buffer[0][i];

    // delete first & shift
    delete[] buffer[0];
    for (int i = 1; i < buffer_size; i++)
        buffer[i - 1] = buffer[i];
    buffer[--buffer_size] = nullptr;

    return ret;
}

void LaserScannerDriver::clear_buffer()
{
    // deletion
    for (int i = 0; i < buffer_size; i++)
        { delete[] buffer[i]; buffer[i] = nullptr; }

    // invalidation
    buffer_size = 0;
}

double LaserScannerDriver::get_distance(double a) const
{
    // base checks
    if (!buffer_size)
        throw std::length_error("** Buffer is empty **");
    if (a < 0 || a > 180)
        throw std::invalid_argument("** Angle must be between 0 and 180 **");

    // index
    int ret_index = (int)round(a / resolution);
    
    // limit case
    if (ret_index >= readings_number)
        ret_index = readings_number - 1;
    
    return buffer[buffer_size - 1][ret_index];
}

std::vector<double> LaserScannerDriver::get_last_scan() const
{
    // base check
    if (!buffer_size)
        throw std::length_error("** Buffer is empty **");
    
    // saving vector
    std::vector<double> ret(readings_number);
    for (int i = 0; i < readings_number; i++)
        ret.at(i) = buffer[buffer_size - 1][i];

    return ret;
}

std::ostream &operator<<(std::ostream &os, const LaserScannerDriver &lsd)
{
    std::vector<double> p = lsd.get_last_scan();

    // printing vector
    for (int i = 0; i < p.size(); i++)
        os << p.at(i) << " ";
    return os;
}