package org.jlab.ersap.demo.services;

import org.jlab.ersap.demo.core.Image;
import org.jlab.ersap.demo.core.ImageWriter;
import org.jlab.ersap.demo.data.ImageDataType;
import org.jlab.ersap.engine.EngineDataType;
import org.jlab.ersap.std.services.AbstractEventWriterService;
import org.jlab.ersap.std.services.EventWriterException;
import org.json.JSONObject;
import org.opencv.core.Core;

import java.io.IOException;
import java.nio.file.Path;

/**
 * A service that writes images into a ZIP file.
 */
public class ImageWriterService extends AbstractEventWriterService<ImageWriter> {

    /**
     * Creates a new image writer service.
     */
    public ImageWriterService() {
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
    }

    @Override
    protected ImageWriter createWriter(Path file, JSONObject opts) throws EventWriterException {
        try {
            return new ImageWriter(file);
        } catch (IOException e) {
            throw new EventWriterException(e);
        }
    }

    @Override
    protected void closeWriter() {
        try {
            writer.close();
        } catch (Exception e) {
            // ignore
        }
    }

    @Override
    protected void writeEvent(Object event) throws EventWriterException {
        Image img = (Image) event;
        writer.writeImage(img.mat(), img.name());
    }

    @Override
    protected EngineDataType getDataType() {
        return ImageDataType.INSTANCE;
    }
}
