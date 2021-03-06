package org.jlab.ersap.demo.core;

import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.MatOfRect;
import org.opencv.core.Point;
import org.opencv.core.Rect;
import org.opencv.core.Scalar;
import org.opencv.core.Size;
import org.opencv.imgproc.Imgproc;
import org.opencv.objdetect.CascadeClassifier;

/**
 * Writes a rectangle around detected faces in a given image.
 */
public class FaceDetector {

    private final CascadeClassifier faceDetector;

    /**
     * Creates a new detector.
     * @param classifier path to the classifier setup filename.
     */
    public FaceDetector(String classifier) {
        faceDetector = new CascadeClassifier(classifier);
    }

    /**
     * Runs the detector on the given image.
     *
     * @param image the input image
     * @return a new image with rectangles over faces
     */
    public Mat run(Mat image) {
        System.out.println("\nRunning FaceDetector");

        // Sharpen image
        Mat source = image;
        Mat destination = new Mat(image.rows(), image.cols(), image.type());
        for (int i = 0; i < 3; i++) {
            Imgproc.GaussianBlur(source, destination, new Size(0, 0), 10);
            Core.addWeighted(source, 1.5, destination, -0.5, 0, destination);
            source = destination;
            destination = new Mat(image.rows(), image.cols(), image.type());
        }

        // Detect faces in the image.
        MatOfRect faceDetections = new MatOfRect();
        faceDetector.detectMultiScale(source, faceDetections);
        System.out.println(String.format("Detected %s faces", faceDetections.toArray().length));

        // Draw a bounding box around each face.
        if (!faceDetections.empty()) {
            for (Rect rect : faceDetections.toArray()) {
                Point p1 = new Point(rect.x, rect.y);
                Point p2 = new Point(rect.x + rect.width, rect.y + rect.height);
                Imgproc.rectangle(source, p1, p2, new Scalar(0, 255, 0));
            }
        }

        return source;
    }
}
