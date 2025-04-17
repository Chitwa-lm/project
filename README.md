# Speed Converter

A command-line utility written in C++ that converts speeds between different units of measurement.

## Features

- Convert from kilometers per hour (km/h) to:
  - Meters per second (m/s)
  - Miles per hour (mph)
  - Knots
- Convert to kilometers per hour (km/h) from:
  - Meters per second (m/s)
  - Miles per hour (mph)
  - Knots
- Input validation to ensure valid numeric inputs
- User-friendly command-line interface
- Precise calculations with two decimal places

## Installation

1. Ensure you have a C++ compiler installed on your system
2. Clone or download this repository
3. Compile the source code:
   ```bash
   g++ speed_converter.cpp -o speed_converter
   ```
4. Run the executable:
   ```bash
   ./speed_converter
   ```

## Usage

1. When you run the program, you'll see a menu with three options:
   - Convert from Kilometers per hour
   - Convert to Kilometers per hour
   - Exit

2. Choose your desired conversion direction by entering 1 or 2

3. Follow the prompts to:
   - Select the target unit for conversion
   - Enter the speed value

4. The program will display the converted value

5. You can continue making conversions or choose option 3 to exit

## Code Structure

The program is organized in a `SpeedConverter` class that contains:

- Conversion constants for accurate calculations
- Methods for converting between different speed units
- Input validation and error handling
- User interface management

## Example Usage

```
Welcome to Speed Converter!

Speed Converter Menu:
1. Convert from Kilometers per hour
2. Convert to Kilometers per hour
3. Exit
Enter your choice (1-3): 1

Enter speed in kilometers per hour: 100

Convert to:
1. Meters per second
2. Miles per hour
3. Knots
Enter your choice (1-3): 1

100.00 km/h = 27.78 m/s
```

## Error Handling

The program includes robust error handling for:
- Invalid numeric inputs
- Negative speed values
- Invalid menu selections

## License

This project is open source and available for use and modification.