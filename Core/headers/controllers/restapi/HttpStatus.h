//
// Created by siulo on 02/01/2025.
//

#ifndef DHMS_HTTPSTATUS_H
#define DHMS_HTTPSTATUS_H

/*
 * This is a non-complete enumeration of all HTTP Status. It must be completed as you need.
 * A complete list of all HTTP Status can be found at https://en.wikipedia.org/wiki/List_of_HTTP_status_codes
 */
enum HttpStatus {
    HTTP_OK = 200,
    HTTP_OK_CREATED = 201,
    HTTP_OK_EMPTY = 204,
    HTTP_REDIRECT = 300,
    HTTP_CLIENT_ERROR_BAD_REQUEST = 400,
    HTTP_CLIENT_ERROR_NOT_AUTH = 401,
    HTTP_CLIENT_ERROR_FORBIDDEN = 403,
    HTTP_CLIENT_ERROR_NOT_FOUND = 404,
    HTTP_SERVER_ERROR = 500,
    HTTP_SERVER_ERROR_NOT_IMPLEMENTED = 501
};

#endif //DHMS_HTTPSTATUS_H
