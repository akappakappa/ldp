/**
 * @file LaserScannerDriver.hpp
 * @author Andrea Valentinuzzi matr1219617
 * @brief Module that manages data from a LIDAR.
 * @date 2020-11-26
 */

/**
 * This module receives scans from the sensor and gives to the user when needed. \n
 * The scans are saved in a buffer of size 10 and each scan contains a set of readings. \n
 * The number of readings for each scan depends on the scanner resolution. \n
 * All the readings are saved in a matrix in free store. \n
 * There are 10 double* pointers inside a double** buffer. \n
 * Each of those pointers points to the first element of a scan.
 */

#include <iostream>
#include <vector>

/**
 * @class LaserScannerDriver
 * @brief Class that manages data from a LIDAR
 * 
 * @invariant BUFFER_DIM >= 0
 * @invariant resolution >= 0.1 && resolution <= 1
 * @invariant buffer == double*[BUFFER_DIM]
 * @invariant buffer_size >= 0 && buffer_size <= BUFFER_DIM
 * @invariant readings_number == (int)(180 / resolution) + 1
 */
class LaserScannerDriver
{
private:
    /** @brief Fixed value for the number of scans. */
    const int BUFFER_DIM = 10;
    /** @brief Value of the scanner resolution, changes only with operator=. */
    double resolution;
    /** @brief Pointer to the buffer of double*. */
    double **buffer;
    /** @brief Currently occupied buffer slots. */
    int buffer_size;
    /** @brief Number of readings for each scan, depends on the resolution. */
    int readings_number;

public:
    /**
     * @brief Construct a new Laser Scanner Driver object. \n
     *   Initialized all variables and the buffer.
     * 
     * @param r Resolution of the scanner.
     * @throw std::invalid_argument Thrown if resolution isn't between 0.1 and 1.
     */
    LaserScannerDriver(double r);
    /**
     * @brief Default constructor that sets resolution to 1.
     */
    LaserScannerDriver() : LaserScannerDriver(1) {}
    /**
     * @brief Copy constructor. Preserves copied scanner.
     * @note Self reference will trigger default constructor behavior.
     * 
     * @param other Scanner to copy.
     */
    LaserScannerDriver(const LaserScannerDriver &other);
    /**
     * @brief Move constructor. Invalidates copied scanner.
     * @note Self reference will trigger default constructor behavior.
     * 
     * @param other Scanner to move.
     */
    LaserScannerDriver(LaserScannerDriver &&other);
    /**
     * @brief Copy assignment. Preserves copied scanner.
     * @note Self reference will just return *this.
     * 
     * @param other Scanner to copy.
     * @return implicit *this
     */
    LaserScannerDriver &operator=(const LaserScannerDriver &other);
    /**
     * @brief Move assignment. Invalidates copied scanner.
     * @note Self reference will just return *this.
     * 
     * @param other Scanner to move.
     * @return implicit *this
     */
    LaserScannerDriver &operator=(LaserScannerDriver &&other);
    /**
     * @brief Destroy the Laser Scanner Driver object.
     */
    ~LaserScannerDriver();

    /**
     * @brief Adds a new scan from the sensor to the buffer. \n
     *   If the buffer is full deletes oldest scan to make space.
     * 
     * @param v Input vector cointaining the readings.
     * @throw std::invalid_argument Thrown if a value is < 0.
     */
    void new_scan(const std::vector<double> &v);
    /**
     * @brief Deletes the oldest scan present in the buffer.
     * 
     * @return A vector containing the readings from the deleted scan.
     * @throw std::length_error Thrown if the buffer is empty.
     */
    std::vector<double> get_scan();
    /**
     * @brief Deletes all scans in the buffer, without deleting the buffer itself.
     */
    void clear_buffer();
    /**
     * @brief Provides the user with the distance corresponding to the input angle.
     * 
     * @param a Input angle.
     * @return Distance corresponding to the angle.
     * @throw std::length_error Thrown if the buffer is empty.
     * @throw std::invalid_argument Thrown if the angle isn't between [0, 180].
     */
    double get_distance(double a) const;

    /**
     * @brief Provides the user with the latest scan present in the buffer.
     * 
     * @return A vector containing the readings from the latest scan.
     * @throw std::length_error Thrown if the buffer is empty.
     * @see operator<< Uses this member function.
     */
    std::vector<double> get_last_scan() const;
};

/**
 * @brief Overloads the operator<< in order to print the last scan in the scanner.
 * 
 * @param os Output stream desired.
 * @param lsd Target scanner.
 * @return Reference to the output stream.
 * @see LaserScannerDriver::get_last_scan Function that provides the latest scan.
 * @relatesalso LaserScannerDriver
 */
std::ostream &operator<<(std::ostream &os, const LaserScannerDriver &lsd);