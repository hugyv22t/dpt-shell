package com.luoye.dpt.model;

import java.util.Arrays;

/**
 * @author luoyesiqiu
 */
public class Instruction {

    public int getMethodIndex() {
        return methodIndex;
    }

    public void setMethodIndex(int methodIndex) {
        this.methodIndex = methodIndex;
    }

    public int getInstructionDataSize() {
        return instructionDataSize;
    }

    public void setInstructionDataSize(int instructionDataSize) {
        this.instructionDataSize = instructionDataSize;
    }

    public byte[] getInstructionsData() {
        return instructionsData;
    }

    public void setInstructionsData(byte[] instructionsData) {
        this.instructionsData = instructionsData;
    }

    @Override
    public String toString() {
        return "Instruction{" +
                "methodIndex=" + methodIndex +
                ", instructionDataSize=" + instructionDataSize +
                ", instructionsData=" + Arrays.toString(instructionsData) +
                '}';
    }


    //Corresponding method_idx in dex
    private int methodIndex;
    //instructionsData size
    private int instructionDataSize;
    //insns data
    private byte[] instructionsData;
}
