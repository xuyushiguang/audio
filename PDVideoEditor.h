
#import <Foundation/Foundation.h>

#import <AVFoundation/AVFoundation.h>
#import <CoreMedia/CMTime.h>


typedef void(^PDVideoEditorExportComplete)(NSString *mediaPath, NSError *error);
@interface PDVideoEditor : NSObject

// Set these properties before building the composition objects.
@property (nonatomic, copy) NSArray *clips; // array of AVURLAssets
@property (nonatomic, copy) NSArray *clipTimeRanges; // array of CMTimeRanges stored in NSValues.
@property (nonatomic) CMTime transitionDuration;

@property (nonatomic, readonly, retain) AVMutableComposition *composition;
@property (nonatomic, readonly, retain) AVMutableVideoComposition *videoComposition;
@property (nonatomic, readonly, retain) AVMutableAudioMix *audioMix;

// Builds the composition and videoComposition
- (void)buildCompositionObjectsForPlayback;

- (void)exportWithCompletionBlock:(PDVideoEditorExportComplete)completeBlock export_progress_block:(void (^)(CGFloat progress))progress_block;

- (AVPlayerItem *)playerItem;


@end
