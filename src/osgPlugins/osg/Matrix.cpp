#include "Matrix.h"

bool readMatrix(osg::Matrix& matrix, osgDB::Input& fr)
{
    bool iteratorAdvanced = false;
    
    if (fr.matchSequence("Matrix {"))
    {

        int entry = fr[0].getNoNestedBrackets();

        fr += 2;

        int row=0;
        int col=0;
        while (!fr.eof() && fr[0].getNoNestedBrackets()>entry)
        {
            if (fr[0].getFloat(matrix(row,col)))
            {
                ++col;
                if (col>=4)
                {
                    col = 0;
                    ++row;
                }
                ++fr;
            }
            else fr.advanceOverCurrentFieldOrBlock();
        }
        iteratorAdvanced = true;
    }        
        
    return iteratorAdvanced;
}


bool writeMatrix(const osg::Matrix& matrix, osgDB::Output& fw)
{
    fw.indent() << "Matrix {" << std::endl;
    fw.moveIn();
    fw.indent() << matrix(0,0) << " " << matrix(0,1) << " " << matrix(0,2) << " " << matrix(0,3) << std::endl;
    fw.indent() << matrix(1,0) << " " << matrix(1,1) << " " << matrix(1,2) << " " << matrix(1,3) << std::endl;
    fw.indent() << matrix(2,0) << " " << matrix(2,1) << " " << matrix(2,2) << " " << matrix(2,3) << std::endl;
    fw.indent() << matrix(3,0) << " " << matrix(3,1) << " " << matrix(3,2) << " " << matrix(3,3) << std::endl;
    fw.moveOut();
    fw.indent() << "}"<< std::endl;
    return true;
}

