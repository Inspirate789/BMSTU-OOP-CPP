#ifndef ERRORS_H
#define ERRORS_H

typedef enum
{
    SUCCESS,
    FILE_OPEN_ERROR,
    MEMORY_ALLOCATE_ERROR,
    MEMORY_ERROR,
    INCORRECT_COMMAND,
    INCORRECT_NUMBER,
    INCORRECT_POINTS_COUNT,
    INCORRECT_LINKAGES_COUNT,
    INCORRECT_POINT_DATA,
    INCORRECT_LINKAGE_DATA,
    // ...
} error_t;

void HandleError(const error_t &error);

#endif // ERRORS_H
