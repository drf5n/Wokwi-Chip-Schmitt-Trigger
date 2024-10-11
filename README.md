# Wokwi-Chip-Schmitt-Trigger
## Description

Schmitt Trigger custom-chip for Wokwi

-  

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
"dependencies": { "chip-schmitt": "github:drf5n/Wokwi-Chip-Schmitt-Trigger@1.0.0" }
```

Then, add the chip to your circuit by adding a `chip-schmitt` item to the `parts` section of `diagram.json`:

```json
  "parts": {
    ...,
    {
      "type": "chip-schmitt",
      "id": "schmitt1",
      "attrs": { }
    },
```

The actual source code for the chip lives in [src/main.c](https://github.com/drf5n/Wokwi-Chip-Schmitt-Trigger/blob/main/src/main.c),
and the pins are described in [chip.json](https://github.com/drf5n/Wokwi-Chip-Schmitt-Trigger/blob/main/chip.json).

This is a copy of the custom chip in
https://wokwi.com/projects/411407134995176449 


The Board/board.svg is scaled down from https://commons.wikimedia.org/wiki/File:Schmitt_trigger_symbol.svg

## Examples

* [Schmitt Trigger Demo -- tabbed](https://wokwi.com/projects/411407134995176449)

## See also:

* https://discord.com/channels/787627282663211009/954892209486966825/1294135480312528957
  -- Discord discussion


## Versions
* github:drf5n/Wokwi-Chip-Schmitt-Trigger@1.0.0 -- Working release

# notes on making a Wokwi custom chip work with Github repository dependency
To get the Wokwi build script working to build the necessary chip.zip file for distribution with a release so Wokwi can pick it up

1) enable the repository settings for wokflow permissions to be read-write
2) make sure the .github/workflows/build.yaml is in the repository
3) commit
4) make a vN.n.n tag: `git tag -a "v1.0.5" -m "build.yaml"`
5) push the tag  to github: `git push origin tag v1.0.5`

Refer to
https://discord.com/channels/787627282663211009/954892209486966825/1274569798231130163
for a little discussion on workflow.


## License

This project is licensed under the MIT license. See the [LICENSE](https://github.com/drf5na/Wokwi-Chip-Schmitt-Trigger/blob/main/LICENSE) file for more details.
