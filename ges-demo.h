#ifndef GESDEMO_H
#define GESDEMO_H

#include <unistd.h>
#include <stdio.h>
#include <gst/gst.h>
#include <ges/ges.h>

static const char *const profiles[][4] = {
  {"application/ogg", "audio/x-vorbis", "video/x-theora", "ogv"},
  {"video/webm", "audio/x-vorbis", "video/x-vp8", "webm"},
  {"video/quicktime,variant=iso", "audio/mpeg,mpegversion=1,layer=3",
      "video/x-h264", "mp4"},
  {"video/x-matroska", "audio/x-vorbis", "video/x-h264", "mkv"},
};

typedef struct DurationPipeline DurationPipeline;
struct DurationPipeline
{
  GESPipeline *pipeline;
  GstClockTime duration;
};

typedef enum
{
  PROFILE_NONE = -1,
  PROFILE_VORBIS_THEORA_OGG,
  PROFILE_VORBIS_VP8_WEBM,
  PROFILE_AAC_H264_QUICKTIME,
  PROFILE_VORBIS_H264_MATROSKA,
} EncodingProfile;

gchar *dataPath;

char * path (const char *filenName);

GESClip * placeAsset (GESLayer * layer, gchar * get_path, gint start, gint in, gint dur);

void busMessageCb (GstBus * bus, GstMessage * message, GMainLoop * mainloop);

GstEncodingProfile * encoderProfile (EncodingProfile type, int width, int height, int fps);

gboolean durationQuerier (DurationPipeline * dpipeline);

void renderPipeline (GESPipeline * pipeline, EncodingProfile prof, const gchar *name);

DurationPipeline *newPipeline(GESTimeline * timeline);
void runJob (GESTimeline * timeline, const gchar *name, EncodingProfile prof);

void play (GESTimeline * timeline);
void render (GESTimeline * timeline, const gchar * name, EncodingProfile prof);

GESTimeline * transitionTL (void);
GESTimeline * effectTL (void);
GESTimeline * testTL (void);
GESTimeline * minuteTL (void);
GESTimeline * imageTL (void);
GESTimeline * oneTL (void);

#endif // GESDEMO_H