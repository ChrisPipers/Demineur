#ifndef POSITION_H
#define POSITION_H


namespace model {

/** \Position
 *
 * @brief The Position class is used for simplify the modified
 * the board or know the valor at a position in the board
 *
 */
class Position{

public:

   /**
   * @brief Position
   *
   * This is the constructor of the class Position without parameter
   *
   */
   Position ();

   /**
    * @brief Position
    *
    * This is the constructor of the class Position with two parameter
    * abs for the abscissa and ord for ordered
    *
    * @param abs is the valor of ordered for build a position
    *
    * @param ord is the valor of abscissa for build a position
    */
   Position(int abs, int ord);

   /**
    * @brief getAbs
    *
    * This method is the getter who allows to know the valor of the abscissa
    *
    * @return an integer which the valor of the abscissa
    */
   int getAbs();

   /**
    * @brief getOrd
    *
    * This method is the getter who allows to know the valor of the ordered
    *
    * @return an integer which the valor of the ordered
    */
   int getOrd();

   /**
    * @brief setAbs
    *
    * This method is the setter to can modified the valor of the abscissa of
    * a position by the int abs
    *
    * @param abs is an integer by which modify the abscissa of the position
    */
   void setAbs(int abs);

   /**
    * @brief setOrd
    *
    * This method is the setter to can modified the valor of the ordered of
    * a position by the int ord
    *
    * @param ord is an integer by which modify the ordered of the position
    */
   void setOrd(int ord);

   /**
    * @brief operator ==
    *
    * This method allows to know if two position are equals
    *
    * @param pos1 is the second position to verify if the first position
    * which the method is apply if they are equals
    *
    * @return a boolean if the two position are eguals
    */
   bool operator==( const Position &pos1) const  ;

   //bool operator==(const Position& pos2, const Position& pos1)const;

   /**
    * @brief operator <
    *
    * This method allows to know if the position in parameter is smaller to the
    * position where is apply this method
    *
    * @param pos1 is the second position to verify if the ordonate or the abscissa
    * are to smaller to the the position whete is apply this method
    *
    * @return a boolean if the two position in parameter is smaller to the position
    * where is apply this method
    */
   bool operator<( const Position& pos1) const ;


private:

    /**
     * @brief abs_
     *
     * This attribute is the valor of the abscissa of the position
     *
     */
    int abs_;

    /**
     * @brief ord_
     *
     * This attribute is the valor of the ordered of the position
     *
     */
    int ord_;

};

}


#endif // POSITION_H
