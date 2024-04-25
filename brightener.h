#pragma once
#include "image.h"

namespace Brightener
{
	int BrightenWholeImage(std::shared_ptr<Image> inputImage)
	{
		int attenuatedPixelCount = 0;

		auto BrightnerFun = [&attenuatedPixelCount](uint8_t pixelGrayscale) {
			uint8_t outputGrayscale = pixelGrayscale;
			if (outputGrayscale > (255 - 25)) {
				++attenuatedPixelCount;
				outputGrayscale = 255;
			}
			else {
				outputGrayscale += 25;
			}

			return outputGrayscale;
		};

		inputImage->pixelRunner(BrightnerFun);

		return attenuatedPixelCount;
	}
}
