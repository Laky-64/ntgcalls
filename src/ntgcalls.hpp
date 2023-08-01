//
// Created by Laky64 on 29/07/2023.
//

#ifndef NTGCALLS_NTGCALLS_HPP
#define NTGCALLS_NTGCALLS_HPP

#include <iostream>
#include "rtc/rtc.hpp"
#include <nlohmann/json.hpp>
#include "SdpBuilder.hpp"
#include "stream.hpp"

using nlohmann::json;

class NTgCalls
{
private:
    std::shared_ptr<rtc::PeerConnection> connection;
    std::shared_ptr<rtc::Track> audioTrack;
    std::shared_ptr<rtc::Track> videoTrack;
    uint32_t audioSource;
    std::vector<uint32_t> sourceGroups;

    std::optional<JoinVoiceCallParams> init(const std::optional<Stream>& audioStream,
               const std::optional<Stream>& videoStream);

public:
    std::string createCall();
    void setRemoteCallParams(const std::string& jsonData);
};

#endif