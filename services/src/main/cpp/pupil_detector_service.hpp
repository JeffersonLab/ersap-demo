#ifndef SCIA_RESAMPLING_SERVICE_HPP
#define SCIA_RESAMPLING_SERVICE_HPP

#include <ersap/engine.hpp>

#include <atomic>
#include <memory>

namespace ersap {
namespace demo {

class PupilDetector;

class PupilDetectorService : public ersap::Engine
{
public:
    PupilDetectorService() = default;

    PupilDetectorService(const PupilDetectorService&) = delete;
    PupilDetectorService& operator=(const PupilDetectorService&) = delete;

    PupilDetectorService(PupilDetectorService&&) = default;
    PupilDetectorService& operator=(PupilDetectorService&&) = default;

    ~PupilDetectorService() override = default;

public:
    ersap::EngineData configure(ersap::EngineData&) override;

    ersap::EngineData execute(ersap::EngineData&) override;

    ersap::EngineData execute_group(const std::vector<ersap::EngineData>&) override;

public:
    std::vector<ersap::EngineDataType> input_data_types() const override;

    std::vector<ersap::EngineDataType> output_data_types() const override;

    std::set<std::string> states() const override;

public:
    std::string name() const override;

    std::string author() const override;

    std::string description() const override;

    std::string version() const override;

private:
    std::shared_ptr<PupilDetector> detector_{};
};

} // end namespace demo
} // end namespace ersap

#endif
