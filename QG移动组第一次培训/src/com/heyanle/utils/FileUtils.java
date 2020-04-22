package com.heyanle.utils;

import java.io.File;

/**
 * Created by HeYanLe on 2020/4/22 0022.
 * https://github.com/heyanLE
 */
public class FileUtils {

    public static File toFile(String path){
        File file = new File(path);
        if(file.isFile() && file.exists()){
            return file;
        }
        return null;
    }


    public static File toTargetPath(String targetPath){
        File file = new File(targetPath);
        if(file.isDirectory()){
            return file;
        }
        return null;
    }

}
