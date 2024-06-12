//
//  Renderer.h
//  metal_view_test
//
//  Created by Manuel Cabrerizo on 10/06/2024.
//

#ifndef Renderer_h
#define Renderer_h

#import <Metal/Metal.h>
#import <QuartzCore/CAMetalLayer.h>
#import "ShaderTypes.h"

typedef struct RenderBatch {
    int bufferIndex;
    //id<MTLCommandBuffer> _Nullable commandBuffer;
    //id<MTLRenderCommandEncoder> _Nullable renderEncoder;
} RenderBatch;

@interface Renderer : NSObject

- (nonnull instancetype)initWithMetalDevice:(nonnull id<MTLDevice>)device
                        drawablePixelFormat:(MTLPixelFormat)drawabklePixelFormat;

- (void)drawableResize:(CGSize)drawableSize;

- (void)frame_begin:(nonnull CAMetalLayer *)layer;
- (void)frame_end:(nonnull CAMetalLayer *)layer;

- (void)render_batch_begin:(RenderBatch *_Nonnull) batch
               first_batch:(bool) first;
- (void)render_batch_end:(RenderBatch *_Nonnull) batch;

- (void)set_proj:(matrix_float4x4) proj;
- (void)set_view:(matrix_float4x4) view;

- (void)draw_quad:(matrix_float4x4)world
            batch:(RenderBatch *_Nonnull)batch;

- (int)get_free_wbuffer;
@end

#endif /* Renderer_h */
