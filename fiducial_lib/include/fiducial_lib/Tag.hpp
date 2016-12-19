// Copyright (c) 20013 by Wayne C. Gramlich.  All rights reserved.

#if !defined(TAG_H_INCLUDED)
#define TAG_H_INCLUDED 1

/// @brief *Tag* is a representation of a ceiling fiducial marker.
///
/// A *Tag* represents a 5-tuple:
///
///        (id, twist, x, y, arcs)
///
/// where:
///
/// * *id* is the tag identifier,
///
/// * *twist* is the amount the tag is twisted from the floor X axis,
///
/// * *x* is the absolute X floor coordinate of the center of *Tag*,
///
/// * *y* is the absolute Y floor coordinate of the center of *Tag*,
///
/// * *arcs* is a list of 0, 1, or more *Arc*'s that connect to other
///   *Tag*'s.
///
/// *twist* needs a little more discussion.  The bottom edge of the
/// fiducial establishes a coordinate system for the *Tag*.  The vector
/// from the lower left corner to the lower right corner is the Tag "X"
/// axis.  Here is some crude ASCII art:
///
///        UL-------UR
///        |         |
///        |    O----+------> "X axis"
///        |         |
///        LL-------LR
///
/// The four corners are labeled UL, UR, LL, and LR for Upper Left, Upper
/// Right, Lower Left, and Lower Right respectively.  O stands for Origin
/// and is located in the exact center of the fiducial.  The "X axis"
/// for the fiducial goes to the left starting from the origin (O) and
/// moving to the right.  The "X axis" is parallel the line the goes
/// through the points LL and LR.
///
/// Internally, *twist* is represented in radians.

#include <vector>

#include "Bounding_Box.hpp"
#include "CV.hpp"
#include "File.hpp"
#include "SVG.hpp"

/// @brief A *Tag_Struct* represents the location and orientation of one 
/// ceiling fiducial tag.
class Tag {
  public:
    /// @brief Fiducial tag diagnal distance in camera pixels.
    double diagonal;

    /// @brief Distance along one side of the tag in world units.
    double world_diagonal;

    ///@brief True if rest of *Tag* is initialized.
    bool initialized;

    /// @brief Distance from origin in hops:
    unsigned int hop_count;

    /// @brief Tag identifier.
    unsigned int id;

    /// @brief The twist from the floor X axis to the tag bottom edge.
    double twist;

    /// @brief True if tag is currently visible in camera field of view.
    bool visible;

    /// @brief Visit counter.
    unsigned int visit;

    /// @brief Absolute X floor coordinate.
    double x;

    /// @brief Absolute Y floor coordinate.
    double y;

    /// @brief Absolute Z floor coordinate.
    double z;

    /// @brief Set if tag was updated
    bool updated;

  public:
    Tag(unsigned int id);

    void initialize(double angle, double x, double y, double diagonal,
        unsigned int visit);

    void svg_write(SVG *svg);
    void write(File out_file);

    // static comparisons and file I/O
    static int equal(Tag *tag1, Tag *tag2);
    static bool less(Tag *tag1, Tag *tag2);
};

// *Tag* routines;


#endif // !defined(TAG_H_INCLUDED)
