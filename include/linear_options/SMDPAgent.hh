#ifndef __SMDP_AGENT_H__
#define __SMDP_AGENT_H__

#include <rl_common/core.hh>
#include <Eigen/Core>

namespace rl {

struct SMDPAgent : public Agent 
{
    /**
     * @param filename Name under which to save the options
     */
    virtual void saveOptions(const std::string& filename) = 0;

    /**
     * Load options from disk into memory. 
     * @param filename Name unde which to save the options
     */
    virtual void loadOptions(const std::string& filename) = 0;

protected:
    /**
     * Convert an STL vector to an Eigen::Vector of double.
     * @param s The vector to convert
     * @return The Eigen::Vector representation.
     */
    Eigen::VectorXd convertVector(const std::vector<float>& s) {
        Eigen::VectorXd out(s.size());
        for (unsigned i = 0; i < s.size(); i++) {
            out(i) = s[i];
        }
        return out; 
    }
};

}
#endif
