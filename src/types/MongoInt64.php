<?hh

/**
* The class can be used to save 64-bit integers to the database on a 32-bit
* system.
*/
class MongoInt64
{
    public $value;

	/**
	* Creates a new 64-bit integer.
	*
	* @param string $value - A number.
	*
	* @return - Returns a new integer.
	*/
    public function __construct(string $value)
    {
        $this->value = $value;
    }

	/**
	* Returns the string representation of this 64-bit integer.
	*
	* @return string - Returns the string representation of this integer.
	*/
    public function __toString()
    {
        return $this->value;
    }
}