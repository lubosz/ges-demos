/*

  Author: Lubosz Sarnecki
  2013

*/

#include <stdlib.h>

#include "ges-demo.h"
#include "ges-renderer.h"

GESTimeline *
testPatternTL (void)
{
  GESTimeline *timeline;
  GESLayer *layer;
  GESTestClip *srca, *srcb;

  timeline = ges_timeline_new_audio_video ();

  layer = ges_layer_new ();
  //g_object_set (layer, "auto-transition", TRUE, NULL);

  ges_timeline_add_layer (timeline, layer);

  srca = ges_test_clip_new ();
  srcb = ges_test_clip_new ();

  // no gst second in duration!
  g_object_set (srca,
      "vpattern", GES_VIDEO_TEST_PATTERN_SMPTE,
      "duration", 5,
      "start", 0, NULL);

  g_object_set (srcb,
      "vpattern", GES_VIDEO_TEST_PATTERN_CIRCULAR,
      "duration", 5,
      "start", 5, NULL);
  ges_test_clip_set_frequency (srcb, 800);

  ges_layer_add_clip (layer, GES_CLIP (srca));
  ges_layer_add_clip (layer, GES_CLIP (srcb));

  /*
     tr = ges_transition_clip_new_for_nick ("crossfade");
     g_object_set (tr,
     "start", tdur * GST_SECOND,
     "duration", tst * GST_SECOND, 
     "in-point", 0, 
     NULL);
     ges_layer_add_clip (layer1, GES_CLIP (tr));
   */
  ges_timeline_commit (timeline);

  return timeline;
}

GESTimeline *
effectTL (void)
{
  GESTimeline *timeline;
  GESLayer *layer;
  GESClip *clip1, *clip2;
  GESEffect *effect1, *effect2;

  timeline = ges_timeline_new_audio_video ();
  layer = ges_layer_new ();

  ges_timeline_add_layer (timeline, layer);

  clip1 = placeAsset (layer, path ("sd/trailer_400p.ogg"), 0, 0, 10);
  clip2 = placeAsset (layer, path ("sd/sintel_trailer-480p.ogv"), 10, 5, 10);

  effect1 = ges_effect_new ("agingtv");
  ges_container_add (GES_CONTAINER (clip1), GES_TIMELINE_ELEMENT (effect1));

  effect2 = ges_effect_new ("rippletv");
  ges_container_add (GES_CONTAINER (clip2), GES_TIMELINE_ELEMENT (effect2));

  ges_timeline_commit (timeline);

  return timeline;
}

GESTimeline *
transitionTL (void)
{
  GESTimeline *timeline;
  GESLayer *layer;

  timeline = ges_timeline_new_audio_video ();
  layer = ges_layer_new ();

  g_object_set (layer, "auto-transition", TRUE, NULL);

  ges_timeline_add_layer (timeline, layer);

  // "sd/sintel_trailer-480p.ogv" makes warnings!

  placeAsset (layer, path ("sd/3D fractal.webm"), 0, 0, 10);
  placeAsset (layer, path ("sd/trailer_400p.ogg"), 7, 5, 10);

  ges_timeline_commit (timeline);

  return timeline;
}

GESTimeline *
testTL (void)
{
  GESTimeline *timeline;
  GESLayer *layer;

  timeline = ges_timeline_new_audio_video ();
  layer = ges_layer_new ();

  ges_timeline_add_layer (timeline, layer);

  GESClip *src = GES_CLIP (ges_test_clip_new ());

  g_object_set (src,
      "vpattern", GES_VIDEO_TEST_PATTERN_SMPTE,
      "duration", 5 * GST_SECOND, NULL);

  ges_layer_add_clip (layer, src);

  ges_timeline_commit (timeline);

  return timeline;
}


GESTimeline *
minuteTL (void)
{
  GESTimeline *timeline;
  GESLayer *layer;

  timeline = ges_timeline_new_audio_video ();
  layer = ges_layer_new ();

  ges_timeline_add_layer (timeline, layer);

  placeAsset (layer,
      path ("sd/Black Ink and Water Test - A Place in Time Song.mp4"),
      0, 0, 15);
  placeAsset (layer, path ("sd/trailer_400p.ogg"), 15, 2, 15);
  placeAsset (layer, path ("sd/sintel_trailer-480p.mp4"), 30, 4, 15);
  placeAsset (layer, path ("hd/fluidsimulation.mp4"), 45, 0, 15);

  ges_timeline_commit (timeline);

  return timeline;
}

GESTimeline *
imageTL (void)
{
  GESTimeline *timeline;
  GESLayer *layer;

  timeline = ges_timeline_new_audio_video ();
  layer = ges_layer_new ();
  //g_object_set (layer, "auto-transition", TRUE, NULL);

  ges_timeline_add_layer (timeline, layer);

  placeAsset (layer, path ("images/LAMP_720_576.jpg"), 0, 0, 2);
  placeAsset (layer, path ("images/Fish.png"), 2, 0, 2);
  placeAsset (layer, path ("images/PNG_transparency_demonstration_1.png"),
      4, 0, 2);
  placeAsset (layer, path ("images/wallpaper-1946968.jpg"), 6, 0, 2);

  ges_timeline_commit (timeline);

  return timeline;
}

GESTimeline *
sameResImageTL (void)
{
  GESTimeline *timeline;
  GESLayer *layer;

  timeline = ges_timeline_new_audio_video ();
  layer = ges_layer_new ();
  //g_object_set (layer, "auto-transition", TRUE, NULL);

  ges_timeline_add_layer (timeline, layer);

  placeAsset (layer, path ("images/test1.jpg"), 0, 0, 10);
  placeAsset (layer, path ("images/test2.jpg"), 10, 0, 10);

  ges_timeline_commit (timeline);

  return timeline;
}

GESTimeline *
hdTL (void)
{
  GESTimeline *timeline;
  GESLayer *layer;

  timeline = ges_timeline_new_audio_video ();
  layer = ges_layer_new ();

  ges_timeline_add_layer (timeline, layer);

  placeAsset (layer, path ("hd/BlenderFluid.webm"), 0, 4, 5);
  placeAsset (layer, path ("hd/fluidsimulation.mp4"), 5, 7, 5);

  ges_timeline_commit (timeline);

  return timeline;
}

GESTimeline *
oneTL (void)
{
  GESTimeline *timeline;
  GESLayer *layer;

  timeline = ges_timeline_new_audio_video ();
  layer = ges_layer_new ();

  ges_timeline_add_layer (timeline, layer);

  placeAsset (layer, path ("sd/trailer_400p.ogg"), 0, 0, 5);

  ges_timeline_commit (timeline);

  return timeline;
}

GESTimeline *
musicTL (void)
{
  GESTimeline *timeline;
  GESLayer *layer = ges_layer_new ();
  GESLayer *audiolayer1 = ges_layer_new ();
  GESLayer *audiolayer2 = ges_layer_new ();

  timeline = ges_timeline_new_audio_video ();

  ges_timeline_add_layer (timeline, layer);
  ges_timeline_add_layer (timeline, audiolayer1);
  ges_timeline_add_layer (timeline, audiolayer2);

  placeAssetType (layer, path ("hd/fluidsimulation.mp4"), 0, 20, 10,
      GES_TRACK_TYPE_VIDEO);
  placeAssetType (audiolayer1, path ("audio/prof.ogg"), 0, 0, 10,
      GES_TRACK_TYPE_AUDIO);
  placeAssetType (audiolayer2, path ("audio/vask.wav"), 2, 0, 7,
      GES_TRACK_TYPE_AUDIO);

  ges_timeline_commit (timeline);

  return timeline;
}

void playTests(void) {
    play(hdTL());
    play(musicTL());
    play(testTL());
    play(transitionTL());
    play(effectTL());
    play(minuteTL());
}

void renderTests(void) {
    render(testTL(), "formats", PROFILE_VORBIS_VP8_WEBM);
    render(testTL(), "formats", PROFILE_VORBIS_THEORA_OGG);
    render(testTL(), "formats", PROFILE_AAC_H264_QUICKTIME);
    render(testTL(), "formats", PROFILE_VORBIS_H264_MATROSKA);

    render(effectTL(), "effect", PROFILE_AAC_H264_QUICKTIME);
    render(minuteTL(), "1minute", PROFILE_AAC_H264_QUICKTIME);

    render(sameResImageTL(), "sameres", PROFILE_AAC_H264_QUICKTIME);

    VideoSize hd = { 1280, 720, 30 };
    renderWithSize(hdTL(), "hd", PROFILE_AAC_H264_QUICKTIME, &hd);
    render(musicTL(), "audio", PROFILE_AAC_H264_QUICKTIME);
}

void brokenRenderTests(void) {
    // muxer resolution problem
    render(imageTL(), "image", PROFILE_AAC_H264_QUICKTIME);
    render(imageTL(), "image", PROFILE_VORBIS_H264_MATROSKA);

    // muxer negotiation problem
    render(testPatternTL(), "testpattern", PROFILE_AAC_H264_QUICKTIME);
    render(transitionTL(), "transition", PROFILE_AAC_H264_QUICKTIME);
}

int
main (int argc, char **argv)
{
  gst_init (NULL, NULL);
  ges_init ();

#ifdef PLATTFORM_WINDOWS
  gchar * path = g_strconcat ("file:///C:/Users/bmonkey/cerbero/dist/windows_x86/bin/data/", NULL);
#else
  char directory[1024];
  getcwd (directory, 1024);
  gchar * path = g_strconcat ("file://", &directory, "/data/", NULL);
#endif
  setPath(path);

  renderTests();

  return 0;
}
