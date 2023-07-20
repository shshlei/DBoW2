/**
 * File: FeatureVector.cpp
 * Date: November 2011
 * Author: Dorian Galvez-Lopez
 * Description: feature vector
 * License: see the LICENSE.txt file
 *
 */

#include "FeatureVector.h"

#include <iostream>
#include <map>
#include <vector>

namespace DBoW2
{
// ---------------------------------------------------------------------------

FeatureVector::FeatureVector(void)
{
}

// ---------------------------------------------------------------------------

FeatureVector::~FeatureVector(void)
{
}

// ---------------------------------------------------------------------------

void FeatureVector::addFeature(NodeId id, std::size_t i_feature)
{
    FeatureVector::iterator vit = this->lower_bound(id);

    if (vit != this->end() && vit->first == id)
    {
        vit->second.push_back(i_feature);
    }
    else
    {
        vit = this->insert(
            vit, FeatureVector::value_type(id, std::vector<std::size_t>()));
        vit->second.push_back(i_feature);
    }
}

// ---------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& out, const FeatureVector& v)
{
    if (!v.empty())
    {
        FeatureVector::const_iterator vit = v.begin();

        const std::vector<std::size_t>* f = &vit->second;

        out << "<" << vit->first << ": [";
        if (!f->empty())
            out << (*f)[0];
        for (std::size_t i = 1; i < f->size(); ++i)
        {
            out << ", " << (*f)[i];
        }
        out << "]>";

        for (++vit; vit != v.end(); ++vit)
        {
            f = &vit->second;

            out << ", <" << vit->first << ": [";
            if (!f->empty())
                out << (*f)[0];
            for (std::size_t i = 1; i < f->size(); ++i)
            {
                out << ", " << (*f)[i];
            }
            out << "]>";
        }
    }

    return out;
}

// ---------------------------------------------------------------------------

}  // namespace DBoW2
