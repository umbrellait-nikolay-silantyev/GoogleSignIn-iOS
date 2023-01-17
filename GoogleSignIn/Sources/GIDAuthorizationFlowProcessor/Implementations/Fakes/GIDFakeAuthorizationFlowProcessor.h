/*
 * Copyright 2023 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "GoogleSignIn/Sources/GIDAuthorizationFlowProcessor/API/GIDAuthorizationFlowProcessor.h"

#ifdef SWIFT_PACKAGE
@import AppAuth;
#else
#import <AppAuth/AppAuth.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/// The block which provides the response for the method `startWithOptions:emmSupport:completion:`.
///
/// @param authorizationResponse The OIDAuthorizationResponse object returned if succeeded.
/// @param error The error returned if failed.
typedef void(^GIDAuthorizationFlowProcessorFakeResponseProviderBlock)
    (OIDAuthorizationResponse *_Nullable authorizationResponse, NSError *_Nullable error);

/// The block to set up response value for the method
/// `startWithOptions:emmSupport:completion:`.
///
/// @param responseProvider The block which provides the response.
typedef void (^GIDAuthorizationFlowProcessorTestBlock)
    (GIDAuthorizationFlowProcessorFakeResponseProviderBlock responseProvider);

@interface GIDFakeAuthorizationFlowProcessor : NSObject <GIDAuthorizationFlowProcessor>

/// The test block which provides the response value.
@property(nonatomic) GIDAuthorizationFlowProcessorTestBlock testBlock;


@end

NS_ASSUME_NONNULL_END
