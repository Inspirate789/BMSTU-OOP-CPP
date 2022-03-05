#include <QMessageBox>

#include "errors.h"

#define MESSAGE_BOX_SIZE_X 500
#define MESSAGE_BOX_SIZE_Y 200

void HandleError(const error_t &error)
{
    QMessageBox message_box;

    switch (error)
    {
        case FILE_OPEN_ERROR:
            message_box.critical(0, "Error","Cannot open file.");
            message_box.setFixedSize(MESSAGE_BOX_SIZE_X, MESSAGE_BOX_SIZE_Y);
            break;
        case MEMORY_ALLOCATE_ERROR:
            message_box.critical(0, "Error","Cannot allocate memory.");
            message_box.setFixedSize(MESSAGE_BOX_SIZE_X, MESSAGE_BOX_SIZE_Y);
            break;
        case MEMORY_ERROR:
            message_box.critical(0, "Error","An invalid pointer was sent for processing.");
            message_box.setFixedSize(MESSAGE_BOX_SIZE_X, MESSAGE_BOX_SIZE_Y);
            break;
        case INCORRECT_COMMAND:
            message_box.critical(0, "Error","Incorrect command was sent to processing.");
            message_box.setFixedSize(MESSAGE_BOX_SIZE_X, MESSAGE_BOX_SIZE_Y);
            break;
        case INCORRECT_NUMBER:
            message_box.critical(0, "Error","Failed to read one of the numbers in the file.");
            message_box.setFixedSize(MESSAGE_BOX_SIZE_X, MESSAGE_BOX_SIZE_Y);
            break;
        case INCORRECT_POINTS_COUNT:
            message_box.critical(0, "Error","The number of points in the file is not correct.");
            message_box.setFixedSize(MESSAGE_BOX_SIZE_X, MESSAGE_BOX_SIZE_Y);
            break;
        case INCORRECT_LINKAGES_COUNT:
            message_box.critical(0, "Error","The number of linkages in the file is not correct.");
            message_box.setFixedSize(MESSAGE_BOX_SIZE_X, MESSAGE_BOX_SIZE_Y);
            break;
        case INCORRECT_POINT_DATA:
            message_box.critical(0, "Error","The coordinates of the points in the file are not correct.");
            message_box.setFixedSize(MESSAGE_BOX_SIZE_X, MESSAGE_BOX_SIZE_Y);
            break;
        case INCORRECT_LINKAGE_DATA:
            message_box.critical(0, "Error","The point linkages in the file are not correct.");
            message_box.setFixedSize(MESSAGE_BOX_SIZE_X, MESSAGE_BOX_SIZE_Y);
            break;
        default:
            message_box.critical(0, "Error","An unhandled error occurred.");
            message_box.setFixedSize(MESSAGE_BOX_SIZE_X, MESSAGE_BOX_SIZE_Y);
            break;
    }
}
