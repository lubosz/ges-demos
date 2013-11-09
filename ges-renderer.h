/*

  Author: Lubosz Sarnecki
  2013

*/

#ifndef GES_RENDERER_H
#define GES_RENDERER_H

#include <unistd.h>
#include <stdio.h>
#include <gst/gst.h>
#include <ges/ges.h>
#include <gst/pbutils/encoding-profile.h>
#include <gst/pbutils/encoding-target.h>

static const char *const profiles[][4] = {
  {"application/ogg", "audio/x-vorbis", "video/x-theora", "ogv"},
  {"video/webm", "audio/x-vorbis", "video/x-vp8", "webm"},
  {"video/quicktime,variant=iso", "audio/mpeg,mpegversion=1,layer=3", "video/x-h264", "mp4"},
  {"video/x-matroska", "audio/x-vorbis", "video/x-h264", "mkv"},
};

typedef enum
{
  PROFILE_NONE = -1,
  PROFILE_VORBIS_THEORA_OGG,
  PROFILE_VORBIS_VP8_WEBM,
  PROFILE_AAC_H264_QUICKTIME,
  PROFILE_VORBIS_H264_MATROSKA
} EncodingProfile;

typedef struct VideoSize VideoSize;
struct VideoSize
{
  gint width;
  gint height;
  gint fps;
};

char *ges_renderer_get_absolute_path (const char *rel_path);
char *replace(char *s, char old, char replacement);

GESClip *ges_clip_unknown_from_rel_path (const gchar * get_path, GESLayer * layer, gint start, gint in,
    gint dur);
GESClip *ges_clip_from_path (const gchar *ges_renderer_get_absolute_path, GESLayer * layer, gint start, gint in,
    gint dur, GESTrackType tt);
GESClip *ges_clip_from_rel_path (const gchar *rel_path, GESLayer * layer, gint start, gint in,
    gint dur, GESTrackType tt);

void bus_message_cb (GstBus * bus, GstMessage * message, GMainLoop * mainloop);

GstEncodingProfile *gst_encoding_profile_from_type (EncodingProfile type, VideoSize * size);

gboolean ges_renderer_print_progress (void);

void ges_pipeline_setup_rendering (GESPipeline * pipeline, EncodingProfile prof,
    const gchar * name, VideoSize * size);

GESPipeline *ges_pipeline_from_timeline (GESTimeline * timeline);
void ges_renderer_run_job (GESTimeline * timeline, const gchar * name, EncodingProfile prof,
    VideoSize * size);

void ges_renderer_play (GESTimeline * timeline);
void ges_renderer_render_pal (GESTimeline * timeline, const gchar * name, EncodingProfile prof);
void ges_renderer_render (GESTimeline * timeline, const gchar * name,
    EncodingProfile prof, VideoSize * size);

void ges_renderer_init_path(void);

GstCaps * gst_caps_from_videosize(VideoSize *size);

GESTimeline * ges_timeline_new_pal(void);
GESTimeline * ges_timeline_audio_video_from_videosize(VideoSize * size);

gint ges_asset_get_structure_int(GESUriClipAsset * asset, const char * name);
gint ges_asset_get_width(GESUriClipAsset *asset);
gint ges_asset_get_height(GESUriClipAsset * asset);

#endif // GES_RENDERER_H
