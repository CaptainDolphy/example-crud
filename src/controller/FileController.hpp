
#ifndef CRUD_FILECONTROLLER_HPP
#define CRUD_FILECONTROLLER_HPP

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/json/ObjectMapper.hpp"
#include "oatpp/macro/codegen.hpp"
#include "oatpp/macro/component.hpp"
#include "oatpp/web/protocol/http/outgoing/StreamingBody.hpp"
#include "oatpp/data/resource/File.hpp"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class FileController : public oatpp::web::server::api::ApiController {
public:
  FileController(const std::shared_ptr<oatpp::web::mime::ContentMappers>& apiContentMappers)
    : oatpp::web::server::api::ApiController(apiContentMappers)
  {}
public:

  static std::shared_ptr<FileController> createShared(
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::mime::ContentMappers>, apiContentMappers) // Inject ContentMappers
  ){
    return std::make_shared<FileController>(apiContentMappers);
  }

ENDPOINT("GET", "download.mp4", downloadFile) {
    auto body = std::make_shared<oatpp::web::protocol::http::outgoing::StreamingBody>(
       oatpp::data::resource::File("/home/test/2024-09-14 14-06-24.mp4").openInputStream()
    );
    return OutgoingResponse::createShared(Status::CODE_200, body);
  }
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif //CRUD_FILECCONTROLLER_HPP
