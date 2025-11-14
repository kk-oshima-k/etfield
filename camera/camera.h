#ifndef CAMERA_H
#define CAMERA_H

#ifdef __cplusplus
extern "C" {
#endif

extern FILE* fp;

#define CAMERA_PRIORITY  (TMIN_APP_TPRI + 3)

extern void initialize_camera();
extern void close_camera();

#ifndef TOPPERS_MACRO_ONLY

extern void camera_task(intptr_t exinf);
extern void camera_cyc(intptr_t exinf);
#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif

#endif // CAMERA_H
