#include "Enums.h"
#include <memory>
#include <cstring>

namespace mxml
{
  AboveBelowEnum::AboveBelowEnum()
  {
  }
  AboveBelowEnum::AboveBelowEnum(const char* value)
  {
    if(strcmp(value, "above")==0) { _value = Above; }
    else if(strcmp(value, "below")==0) { _value = Below; }
    else _value = Invalid;
  }
  AboveBelowEnum::operator const char*() const
  {
    switch(_value) {
      case Above: return "above";
      case Below: return "below";
      default: break;
    }
    return '\0';
  }
  AboveBelowEnum::AboveBelowEnum(InnerEnum value): _value(value)
  {
  }
  AboveBelowEnum::operator InnerEnum() const
  {
    return _value;
  }
  AccidentalValueEnum::AccidentalValueEnum()
  {
  }
  AccidentalValueEnum::AccidentalValueEnum(const char* value)
  {
    if(strcmp(value, "sharp")==0) { _value = Sharp; }
    else if(strcmp(value, "natural")==0) { _value = Natural; }
    else if(strcmp(value, "flat")==0) { _value = Flat; }
    else if(strcmp(value, "double-sharp")==0) { _value = DoubleSharp; }
    else if(strcmp(value, "sharp-sharp")==0) { _value = SharpSharp; }
    else if(strcmp(value, "flat-flat")==0) { _value = FlatFlat; }
    else if(strcmp(value, "natural-sharp")==0) { _value = NaturalSharp; }
    else if(strcmp(value, "natural-flat")==0) { _value = NaturalFlat; }
    else if(strcmp(value, "quarter-flat")==0) { _value = QuarterFlat; }
    else if(strcmp(value, "quarter-sharp")==0) { _value = QuarterSharp; }
    else if(strcmp(value, "three-quarters-flat")==0) { _value = ThreeQuartersFlat; }
    else if(strcmp(value, "three-quarters-sharp")==0) { _value = ThreeQuartersSharp; }
    else if(strcmp(value, "sharp-down")==0) { _value = SharpDown; }
    else if(strcmp(value, "sharp-up")==0) { _value = SharpUp; }
    else if(strcmp(value, "natural-down")==0) { _value = NaturalDown; }
    else if(strcmp(value, "natural-up")==0) { _value = NaturalUp; }
    else if(strcmp(value, "flat-down")==0) { _value = FlatDown; }
    else if(strcmp(value, "flat-up")==0) { _value = FlatUp; }
    else if(strcmp(value, "triple-sharp")==0) { _value = TripleSharp; }
    else if(strcmp(value, "triple-flat")==0) { _value = TripleFlat; }
    else if(strcmp(value, "slash-quarter-sharp")==0) { _value = SlashQuarterSharp; }
    else if(strcmp(value, "slash-sharp")==0) { _value = SlashSharp; }
    else if(strcmp(value, "slash-flat")==0) { _value = SlashFlat; }
    else if(strcmp(value, "double-slash-flat")==0) { _value = DoubleSlashFlat; }
    else if(strcmp(value, "sharp-1")==0) { _value = Sharp1; }
    else if(strcmp(value, "sharp-2")==0) { _value = Sharp2; }
    else if(strcmp(value, "sharp-3")==0) { _value = Sharp3; }
    else if(strcmp(value, "sharp-5")==0) { _value = Sharp5; }
    else if(strcmp(value, "flat-1")==0) { _value = Flat1; }
    else if(strcmp(value, "flat-2")==0) { _value = Flat2; }
    else if(strcmp(value, "flat-3")==0) { _value = Flat3; }
    else if(strcmp(value, "flat-4")==0) { _value = Flat4; }
    else if(strcmp(value, "sori")==0) { _value = Sori; }
    else if(strcmp(value, "koron")==0) { _value = Koron; }
    else _value = Invalid;
  }
  AccidentalValueEnum::operator const char*() const
  {
    switch(_value) {
      case Sharp: return "sharp";
      case Natural: return "natural";
      case Flat: return "flat";
      case DoubleSharp: return "double-sharp";
      case SharpSharp: return "sharp-sharp";
      case FlatFlat: return "flat-flat";
      case NaturalSharp: return "natural-sharp";
      case NaturalFlat: return "natural-flat";
      case QuarterFlat: return "quarter-flat";
      case QuarterSharp: return "quarter-sharp";
      case ThreeQuartersFlat: return "three-quarters-flat";
      case ThreeQuartersSharp: return "three-quarters-sharp";
      case SharpDown: return "sharp-down";
      case SharpUp: return "sharp-up";
      case NaturalDown: return "natural-down";
      case NaturalUp: return "natural-up";
      case FlatDown: return "flat-down";
      case FlatUp: return "flat-up";
      case TripleSharp: return "triple-sharp";
      case TripleFlat: return "triple-flat";
      case SlashQuarterSharp: return "slash-quarter-sharp";
      case SlashSharp: return "slash-sharp";
      case SlashFlat: return "slash-flat";
      case DoubleSlashFlat: return "double-slash-flat";
      case Sharp1: return "sharp-1";
      case Sharp2: return "sharp-2";
      case Sharp3: return "sharp-3";
      case Sharp5: return "sharp-5";
      case Flat1: return "flat-1";
      case Flat2: return "flat-2";
      case Flat3: return "flat-3";
      case Flat4: return "flat-4";
      case Sori: return "sori";
      case Koron: return "koron";
      default: break;
    }
    return '\0';
  }
  AccidentalValueEnum::AccidentalValueEnum(InnerEnum value): _value(value)
  {
  }
  AccidentalValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  ArrowDirectionEnum::ArrowDirectionEnum()
  {
  }
  ArrowDirectionEnum::ArrowDirectionEnum(const char* value)
  {
    if(strcmp(value, "left")==0) { _value = Left; }
    else if(strcmp(value, "up")==0) { _value = Up; }
    else if(strcmp(value, "right")==0) { _value = Right; }
    else if(strcmp(value, "down")==0) { _value = Down; }
    else if(strcmp(value, "northwest")==0) { _value = Northwest; }
    else if(strcmp(value, "northeast")==0) { _value = Northeast; }
    else if(strcmp(value, "southeast")==0) { _value = Southeast; }
    else if(strcmp(value, "southwest")==0) { _value = Southwest; }
    else if(strcmp(value, "left right")==0) { _value = LeftRight; }
    else if(strcmp(value, "up down")==0) { _value = UpDown; }
    else if(strcmp(value, "northwest southeast")==0) { _value = NorthwestSoutheast; }
    else if(strcmp(value, "northeast southwest")==0) { _value = NortheastSouthwest; }
    else if(strcmp(value, "other")==0) { _value = Other; }
    else _value = Invalid;
  }
  ArrowDirectionEnum::operator const char*() const
  {
    switch(_value) {
      case Left: return "left";
      case Up: return "up";
      case Right: return "right";
      case Down: return "down";
      case Northwest: return "northwest";
      case Northeast: return "northeast";
      case Southeast: return "southeast";
      case Southwest: return "southwest";
      case LeftRight: return "left right";
      case UpDown: return "up down";
      case NorthwestSoutheast: return "northwest southeast";
      case NortheastSouthwest: return "northeast southwest";
      case Other: return "other";
      default: break;
    }
    return '\0';
  }
  ArrowDirectionEnum::ArrowDirectionEnum(InnerEnum value): _value(value)
  {
  }
  ArrowDirectionEnum::operator InnerEnum() const
  {
    return _value;
  }
  ArrowStyleEnum::ArrowStyleEnum()
  {
  }
  ArrowStyleEnum::ArrowStyleEnum(const char* value)
  {
    if(strcmp(value, "single")==0) { _value = Single; }
    else if(strcmp(value, "double")==0) { _value = Double; }
    else if(strcmp(value, "filled")==0) { _value = Filled; }
    else if(strcmp(value, "hollow")==0) { _value = Hollow; }
    else if(strcmp(value, "paired")==0) { _value = Paired; }
    else if(strcmp(value, "combined")==0) { _value = Combined; }
    else if(strcmp(value, "other")==0) { _value = Other; }
    else _value = Invalid;
  }
  ArrowStyleEnum::operator const char*() const
  {
    switch(_value) {
      case Single: return "single";
      case Double: return "double";
      case Filled: return "filled";
      case Hollow: return "hollow";
      case Paired: return "paired";
      case Combined: return "combined";
      case Other: return "other";
      default: break;
    }
    return '\0';
  }
  ArrowStyleEnum::ArrowStyleEnum(InnerEnum value): _value(value)
  {
  }
  ArrowStyleEnum::operator InnerEnum() const
  {
    return _value;
  }
  BackwardForwardEnum::BackwardForwardEnum()
  {
  }
  BackwardForwardEnum::BackwardForwardEnum(const char* value)
  {
    if(strcmp(value, "backward")==0) { _value = Backward; }
    else if(strcmp(value, "forward")==0) { _value = Forward; }
    else _value = Invalid;
  }
  BackwardForwardEnum::operator const char*() const
  {
    switch(_value) {
      case Backward: return "backward";
      case Forward: return "forward";
      default: break;
    }
    return '\0';
  }
  BackwardForwardEnum::BackwardForwardEnum(InnerEnum value): _value(value)
  {
  }
  BackwardForwardEnum::operator InnerEnum() const
  {
    return _value;
  }
  BarStyleEnum::BarStyleEnum()
  {
  }
  BarStyleEnum::BarStyleEnum(const char* value)
  {
    if(strcmp(value, "regular")==0) { _value = Regular; }
    else if(strcmp(value, "dotted")==0) { _value = Dotted; }
    else if(strcmp(value, "dashed")==0) { _value = Dashed; }
    else if(strcmp(value, "heavy")==0) { _value = Heavy; }
    else if(strcmp(value, "light-light")==0) { _value = LightLight; }
    else if(strcmp(value, "light-heavy")==0) { _value = LightHeavy; }
    else if(strcmp(value, "heavy-light")==0) { _value = HeavyLight; }
    else if(strcmp(value, "heavy-heavy")==0) { _value = HeavyHeavy; }
    else if(strcmp(value, "tick")==0) { _value = Tick; }
    else if(strcmp(value, "short")==0) { _value = Short; }
    else if(strcmp(value, "none")==0) { _value = None; }
    else _value = Invalid;
  }
  BarStyleEnum::operator const char*() const
  {
    switch(_value) {
      case Regular: return "regular";
      case Dotted: return "dotted";
      case Dashed: return "dashed";
      case Heavy: return "heavy";
      case LightLight: return "light-light";
      case LightHeavy: return "light-heavy";
      case HeavyLight: return "heavy-light";
      case HeavyHeavy: return "heavy-heavy";
      case Tick: return "tick";
      case Short: return "short";
      case None: return "none";
      default: break;
    }
    return '\0';
  }
  BarStyleEnum::BarStyleEnum(InnerEnum value): _value(value)
  {
  }
  BarStyleEnum::operator InnerEnum() const
  {
    return _value;
  }
  BeamValueEnum::BeamValueEnum()
  {
  }
  BeamValueEnum::BeamValueEnum(const char* value)
  {
    if(strcmp(value, "begin")==0) { _value = Begin; }
    else if(strcmp(value, "continue")==0) { _value = Continue; }
    else if(strcmp(value, "end")==0) { _value = End; }
    else if(strcmp(value, "forward hook")==0) { _value = ForwardHook; }
    else if(strcmp(value, "backward hook")==0) { _value = BackwardHook; }
    else _value = Invalid;
  }
  BeamValueEnum::operator const char*() const
  {
    switch(_value) {
      case Begin: return "begin";
      case Continue: return "continue";
      case End: return "end";
      case ForwardHook: return "forward hook";
      case BackwardHook: return "backward hook";
      default: break;
    }
    return '\0';
  }
  BeamValueEnum::BeamValueEnum(InnerEnum value): _value(value)
  {
  }
  BeamValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  BeaterValueEnum::BeaterValueEnum()
  {
  }
  BeaterValueEnum::BeaterValueEnum(const char* value)
  {
    if(strcmp(value, "bow")==0) { _value = Bow; }
    else if(strcmp(value, "chime hammer")==0) { _value = ChimeHammer; }
    else if(strcmp(value, "coin")==0) { _value = Coin; }
    else if(strcmp(value, "finger")==0) { _value = Finger; }
    else if(strcmp(value, "fingernail")==0) { _value = Fingernail; }
    else if(strcmp(value, "fist")==0) { _value = Fist; }
    else if(strcmp(value, "guiro scraper")==0) { _value = GuiroScraper; }
    else if(strcmp(value, "hammer")==0) { _value = Hammer; }
    else if(strcmp(value, "hand")==0) { _value = Hand; }
    else if(strcmp(value, "jazz stick")==0) { _value = JazzStick; }
    else if(strcmp(value, "knitting needle")==0) { _value = KnittingNeedle; }
    else if(strcmp(value, "metal hammer")==0) { _value = MetalHammer; }
    else if(strcmp(value, "snare stick")==0) { _value = SnareStick; }
    else if(strcmp(value, "spoon mallet")==0) { _value = SpoonMallet; }
    else if(strcmp(value, "triangle beater")==0) { _value = TriangleBeater; }
    else if(strcmp(value, "triangle beater plain")==0) { _value = TriangleBeaterPlain; }
    else if(strcmp(value, "wire brush")==0) { _value = WireBrush; }
    else _value = Invalid;
  }
  BeaterValueEnum::operator const char*() const
  {
    switch(_value) {
      case Bow: return "bow";
      case ChimeHammer: return "chime hammer";
      case Coin: return "coin";
      case Finger: return "finger";
      case Fingernail: return "fingernail";
      case Fist: return "fist";
      case GuiroScraper: return "guiro scraper";
      case Hammer: return "hammer";
      case Hand: return "hand";
      case JazzStick: return "jazz stick";
      case KnittingNeedle: return "knitting needle";
      case MetalHammer: return "metal hammer";
      case SnareStick: return "snare stick";
      case SpoonMallet: return "spoon mallet";
      case TriangleBeater: return "triangle beater";
      case TriangleBeaterPlain: return "triangle beater plain";
      case WireBrush: return "wire brush";
      default: break;
    }
    return '\0';
  }
  BeaterValueEnum::BeaterValueEnum(InnerEnum value): _value(value)
  {
  }
  BeaterValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  CancelLocationEnum::CancelLocationEnum()
  {
  }
  CancelLocationEnum::CancelLocationEnum(const char* value)
  {
    if(strcmp(value, "left")==0) { _value = Left; }
    else if(strcmp(value, "right")==0) { _value = Right; }
    else if(strcmp(value, "before-barline")==0) { _value = BeforeBarline; }
    else _value = Invalid;
  }
  CancelLocationEnum::operator const char*() const
  {
    switch(_value) {
      case Left: return "left";
      case Right: return "right";
      case BeforeBarline: return "before-barline";
      default: break;
    }
    return '\0';
  }
  CancelLocationEnum::CancelLocationEnum(InnerEnum value): _value(value)
  {
  }
  CancelLocationEnum::operator InnerEnum() const
  {
    return _value;
  }
  CircularArrowEnum::CircularArrowEnum()
  {
  }
  CircularArrowEnum::CircularArrowEnum(const char* value)
  {
    if(strcmp(value, "clockwise")==0) { _value = Clockwise; }
    else if(strcmp(value, "anticlockwise")==0) { _value = Anticlockwise; }
    else _value = Invalid;
  }
  CircularArrowEnum::operator const char*() const
  {
    switch(_value) {
      case Clockwise: return "clockwise";
      case Anticlockwise: return "anticlockwise";
      default: break;
    }
    return '\0';
  }
  CircularArrowEnum::CircularArrowEnum(InnerEnum value): _value(value)
  {
  }
  CircularArrowEnum::operator InnerEnum() const
  {
    return _value;
  }
  ClefSignEnum::ClefSignEnum()
  {
  }
  ClefSignEnum::ClefSignEnum(const char* value)
  {
    if(strcmp(value, "G")==0) { _value = G; }
    else if(strcmp(value, "F")==0) { _value = F; }
    else if(strcmp(value, "C")==0) { _value = C; }
    else if(strcmp(value, "percussion")==0) { _value = Percussion; }
    else if(strcmp(value, "TAB")==0) { _value = TAB; }
    else if(strcmp(value, "jianpu")==0) { _value = Jianpu; }
    else if(strcmp(value, "none")==0) { _value = None; }
    else _value = Invalid;
  }
  ClefSignEnum::operator const char*() const
  {
    switch(_value) {
      case G: return "G";
      case F: return "F";
      case C: return "C";
      case Percussion: return "percussion";
      case TAB: return "TAB";
      case Jianpu: return "jianpu";
      case None: return "none";
      default: break;
    }
    return '\0';
  }
  ClefSignEnum::ClefSignEnum(InnerEnum value): _value(value)
  {
  }
  ClefSignEnum::operator InnerEnum() const
  {
    return _value;
  }
  CssFontSizeEnum::CssFontSizeEnum()
  {
  }
  CssFontSizeEnum::CssFontSizeEnum(const char* value)
  {
    if(strcmp(value, "xx-small")==0) { _value = XxSmall; }
    else if(strcmp(value, "x-small")==0) { _value = XSmall; }
    else if(strcmp(value, "small")==0) { _value = Small; }
    else if(strcmp(value, "medium")==0) { _value = Medium; }
    else if(strcmp(value, "large")==0) { _value = Large; }
    else if(strcmp(value, "x-large")==0) { _value = XLarge; }
    else if(strcmp(value, "xx-large")==0) { _value = XxLarge; }
    else _value = Invalid;
  }
  CssFontSizeEnum::operator const char*() const
  {
    switch(_value) {
      case XxSmall: return "xx-small";
      case XSmall: return "x-small";
      case Small: return "small";
      case Medium: return "medium";
      case Large: return "large";
      case XLarge: return "x-large";
      case XxLarge: return "xx-large";
      default: break;
    }
    return '\0';
  }
  CssFontSizeEnum::CssFontSizeEnum(InnerEnum value): _value(value)
  {
  }
  CssFontSizeEnum::operator InnerEnum() const
  {
    return _value;
  }
  DegreeSymbolValueEnum::DegreeSymbolValueEnum()
  {
  }
  DegreeSymbolValueEnum::DegreeSymbolValueEnum(const char* value)
  {
    if(strcmp(value, "major")==0) { _value = Major; }
    else if(strcmp(value, "minor")==0) { _value = Minor; }
    else if(strcmp(value, "augmented")==0) { _value = Augmented; }
    else if(strcmp(value, "diminished")==0) { _value = Diminished; }
    else if(strcmp(value, "half-diminished")==0) { _value = HalfDiminished; }
    else _value = Invalid;
  }
  DegreeSymbolValueEnum::operator const char*() const
  {
    switch(_value) {
      case Major: return "major";
      case Minor: return "minor";
      case Augmented: return "augmented";
      case Diminished: return "diminished";
      case HalfDiminished: return "half-diminished";
      default: break;
    }
    return '\0';
  }
  DegreeSymbolValueEnum::DegreeSymbolValueEnum(InnerEnum value): _value(value)
  {
  }
  DegreeSymbolValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  DegreeTypeValueEnum::DegreeTypeValueEnum()
  {
  }
  DegreeTypeValueEnum::DegreeTypeValueEnum(const char* value)
  {
    if(strcmp(value, "add")==0) { _value = Add; }
    else if(strcmp(value, "alter")==0) { _value = Alter; }
    else if(strcmp(value, "subtract")==0) { _value = Subtract; }
    else _value = Invalid;
  }
  DegreeTypeValueEnum::operator const char*() const
  {
    switch(_value) {
      case Add: return "add";
      case Alter: return "alter";
      case Subtract: return "subtract";
      default: break;
    }
    return '\0';
  }
  DegreeTypeValueEnum::DegreeTypeValueEnum(InnerEnum value): _value(value)
  {
  }
  DegreeTypeValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  EffectEnum::EffectEnum()
  {
  }
  EffectEnum::EffectEnum(const char* value)
  {
    if(strcmp(value, "anvil")==0) { _value = Anvil; }
    else if(strcmp(value, "auto horn")==0) { _value = AutoHorn; }
    else if(strcmp(value, "bird whistle")==0) { _value = BirdWhistle; }
    else if(strcmp(value, "cannon")==0) { _value = Cannon; }
    else if(strcmp(value, "duck call")==0) { _value = DuckCall; }
    else if(strcmp(value, "gun shot")==0) { _value = GunShot; }
    else if(strcmp(value, "klaxon horn")==0) { _value = KlaxonHorn; }
    else if(strcmp(value, "lions roar")==0) { _value = LionsRoar; }
    else if(strcmp(value, "police whistle")==0) { _value = PoliceWhistle; }
    else if(strcmp(value, "siren")==0) { _value = Siren; }
    else if(strcmp(value, "slide whistle")==0) { _value = SlideWhistle; }
    else if(strcmp(value, "thunder sheet")==0) { _value = ThunderSheet; }
    else if(strcmp(value, "wind machine")==0) { _value = WindMachine; }
    else if(strcmp(value, "wind whistle")==0) { _value = WindWhistle; }
    else _value = Invalid;
  }
  EffectEnum::operator const char*() const
  {
    switch(_value) {
      case Anvil: return "anvil";
      case AutoHorn: return "auto horn";
      case BirdWhistle: return "bird whistle";
      case Cannon: return "cannon";
      case DuckCall: return "duck call";
      case GunShot: return "gun shot";
      case KlaxonHorn: return "klaxon horn";
      case LionsRoar: return "lions roar";
      case PoliceWhistle: return "police whistle";
      case Siren: return "siren";
      case SlideWhistle: return "slide whistle";
      case ThunderSheet: return "thunder sheet";
      case WindMachine: return "wind machine";
      case WindWhistle: return "wind whistle";
      default: break;
    }
    return '\0';
  }
  EffectEnum::EffectEnum(InnerEnum value): _value(value)
  {
  }
  EffectEnum::operator InnerEnum() const
  {
    return _value;
  }
  EnclosureShapeEnum::EnclosureShapeEnum()
  {
  }
  EnclosureShapeEnum::EnclosureShapeEnum(const char* value)
  {
    if(strcmp(value, "rectangle")==0) { _value = Rectangle; }
    else if(strcmp(value, "square")==0) { _value = Square; }
    else if(strcmp(value, "oval")==0) { _value = Oval; }
    else if(strcmp(value, "circle")==0) { _value = Circle; }
    else if(strcmp(value, "bracket")==0) { _value = Bracket; }
    else if(strcmp(value, "triangle")==0) { _value = Triangle; }
    else if(strcmp(value, "diamond")==0) { _value = Diamond; }
    else if(strcmp(value, "none")==0) { _value = None; }
    else _value = Invalid;
  }
  EnclosureShapeEnum::operator const char*() const
  {
    switch(_value) {
      case Rectangle: return "rectangle";
      case Square: return "square";
      case Oval: return "oval";
      case Circle: return "circle";
      case Bracket: return "bracket";
      case Triangle: return "triangle";
      case Diamond: return "diamond";
      case None: return "none";
      default: break;
    }
    return '\0';
  }
  EnclosureShapeEnum::EnclosureShapeEnum(InnerEnum value): _value(value)
  {
  }
  EnclosureShapeEnum::operator InnerEnum() const
  {
    return _value;
  }
  FanEnum::FanEnum()
  {
  }
  FanEnum::FanEnum(const char* value)
  {
    if(strcmp(value, "accel")==0) { _value = Accel; }
    else if(strcmp(value, "rit")==0) { _value = Rit; }
    else if(strcmp(value, "none")==0) { _value = None; }
    else _value = Invalid;
  }
  FanEnum::operator const char*() const
  {
    switch(_value) {
      case Accel: return "accel";
      case Rit: return "rit";
      case None: return "none";
      default: break;
    }
    return '\0';
  }
  FanEnum::FanEnum(InnerEnum value): _value(value)
  {
  }
  FanEnum::operator InnerEnum() const
  {
    return _value;
  }
  FontStyleEnum::FontStyleEnum()
  {
  }
  FontStyleEnum::FontStyleEnum(const char* value)
  {
    if(strcmp(value, "normal")==0) { _value = Normal; }
    else if(strcmp(value, "italic")==0) { _value = Italic; }
    else _value = Invalid;
  }
  FontStyleEnum::operator const char*() const
  {
    switch(_value) {
      case Normal: return "normal";
      case Italic: return "italic";
      default: break;
    }
    return '\0';
  }
  FontStyleEnum::FontStyleEnum(InnerEnum value): _value(value)
  {
  }
  FontStyleEnum::operator InnerEnum() const
  {
    return _value;
  }
  FontWeightEnum::FontWeightEnum()
  {
  }
  FontWeightEnum::FontWeightEnum(const char* value)
  {
    if(strcmp(value, "normal")==0) { _value = Normal; }
    else if(strcmp(value, "bold")==0) { _value = Bold; }
    else _value = Invalid;
  }
  FontWeightEnum::operator const char*() const
  {
    switch(_value) {
      case Normal: return "normal";
      case Bold: return "bold";
      default: break;
    }
    return '\0';
  }
  FontWeightEnum::FontWeightEnum(InnerEnum value): _value(value)
  {
  }
  FontWeightEnum::operator InnerEnum() const
  {
    return _value;
  }
  GlassEnum::GlassEnum()
  {
  }
  GlassEnum::GlassEnum(const char* value)
  {
    if(strcmp(value, "wind chimes")==0) { _value = WindChimes; }
    else _value = Invalid;
  }
  GlassEnum::operator const char*() const
  {
    switch(_value) {
      case WindChimes: return "wind chimes";
      default: break;
    }
    return '\0';
  }
  GlassEnum::GlassEnum(InnerEnum value): _value(value)
  {
  }
  GlassEnum::operator InnerEnum() const
  {
    return _value;
  }
  GroupBarlineValueEnum::GroupBarlineValueEnum()
  {
  }
  GroupBarlineValueEnum::GroupBarlineValueEnum(const char* value)
  {
    if(strcmp(value, "yes")==0) { _value = Yes; }
    else if(strcmp(value, "no")==0) { _value = No; }
    else if(strcmp(value, "Mensurstrich")==0) { _value = Mensurstrich; }
    else _value = Invalid;
  }
  GroupBarlineValueEnum::operator const char*() const
  {
    switch(_value) {
      case Yes: return "yes";
      case No: return "no";
      case Mensurstrich: return "Mensurstrich";
      default: break;
    }
    return '\0';
  }
  GroupBarlineValueEnum::GroupBarlineValueEnum(InnerEnum value): _value(value)
  {
  }
  GroupBarlineValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  GroupSymbolValueEnum::GroupSymbolValueEnum()
  {
  }
  GroupSymbolValueEnum::GroupSymbolValueEnum(const char* value)
  {
    if(strcmp(value, "none")==0) { _value = None; }
    else if(strcmp(value, "brace")==0) { _value = Brace; }
    else if(strcmp(value, "line")==0) { _value = Line; }
    else if(strcmp(value, "bracket")==0) { _value = Bracket; }
    else if(strcmp(value, "square")==0) { _value = Square; }
    else _value = Invalid;
  }
  GroupSymbolValueEnum::operator const char*() const
  {
    switch(_value) {
      case None: return "none";
      case Brace: return "brace";
      case Line: return "line";
      case Bracket: return "bracket";
      case Square: return "square";
      default: break;
    }
    return '\0';
  }
  GroupSymbolValueEnum::GroupSymbolValueEnum(InnerEnum value): _value(value)
  {
  }
  GroupSymbolValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  HandbellValueEnum::HandbellValueEnum()
  {
  }
  HandbellValueEnum::HandbellValueEnum(const char* value)
  {
    if(strcmp(value, "damp")==0) { _value = Damp; }
    else if(strcmp(value, "echo")==0) { _value = Echo; }
    else if(strcmp(value, "gyro")==0) { _value = Gyro; }
    else if(strcmp(value, "hand martellato")==0) { _value = HandMartellato; }
    else if(strcmp(value, "mallet lift")==0) { _value = MalletLift; }
    else if(strcmp(value, "mallet table")==0) { _value = MalletTable; }
    else if(strcmp(value, "martellato")==0) { _value = Martellato; }
    else if(strcmp(value, "martellato lift")==0) { _value = MartellatoLift; }
    else if(strcmp(value, "muted martellato")==0) { _value = MutedMartellato; }
    else if(strcmp(value, "pluck lift")==0) { _value = PluckLift; }
    else if(strcmp(value, "swing")==0) { _value = Swing; }
    else _value = Invalid;
  }
  HandbellValueEnum::operator const char*() const
  {
    switch(_value) {
      case Damp: return "damp";
      case Echo: return "echo";
      case Gyro: return "gyro";
      case HandMartellato: return "hand martellato";
      case MalletLift: return "mallet lift";
      case MalletTable: return "mallet table";
      case Martellato: return "martellato";
      case MartellatoLift: return "martellato lift";
      case MutedMartellato: return "muted martellato";
      case PluckLift: return "pluck lift";
      case Swing: return "swing";
      default: break;
    }
    return '\0';
  }
  HandbellValueEnum::HandbellValueEnum(InnerEnum value): _value(value)
  {
  }
  HandbellValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  HarmonyTypeEnum::HarmonyTypeEnum()
  {
  }
  HarmonyTypeEnum::HarmonyTypeEnum(const char* value)
  {
    if(strcmp(value, "explicit")==0) { _value = Explicit; }
    else if(strcmp(value, "implied")==0) { _value = Implied; }
    else if(strcmp(value, "alternate")==0) { _value = Alternate; }
    else _value = Invalid;
  }
  HarmonyTypeEnum::operator const char*() const
  {
    switch(_value) {
      case Explicit: return "explicit";
      case Implied: return "implied";
      case Alternate: return "alternate";
      default: break;
    }
    return '\0';
  }
  HarmonyTypeEnum::HarmonyTypeEnum(InnerEnum value): _value(value)
  {
  }
  HarmonyTypeEnum::operator InnerEnum() const
  {
    return _value;
  }
  HoleClosedLocationEnum::HoleClosedLocationEnum()
  {
  }
  HoleClosedLocationEnum::HoleClosedLocationEnum(const char* value)
  {
    if(strcmp(value, "right")==0) { _value = Right; }
    else if(strcmp(value, "bottom")==0) { _value = Bottom; }
    else if(strcmp(value, "left")==0) { _value = Left; }
    else if(strcmp(value, "top")==0) { _value = Top; }
    else _value = Invalid;
  }
  HoleClosedLocationEnum::operator const char*() const
  {
    switch(_value) {
      case Right: return "right";
      case Bottom: return "bottom";
      case Left: return "left";
      case Top: return "top";
      default: break;
    }
    return '\0';
  }
  HoleClosedLocationEnum::HoleClosedLocationEnum(InnerEnum value): _value(value)
  {
  }
  HoleClosedLocationEnum::operator InnerEnum() const
  {
    return _value;
  }
  HoleClosedValueEnum::HoleClosedValueEnum()
  {
  }
  HoleClosedValueEnum::HoleClosedValueEnum(const char* value)
  {
    if(strcmp(value, "yes")==0) { _value = Yes; }
    else if(strcmp(value, "no")==0) { _value = No; }
    else if(strcmp(value, "half")==0) { _value = Half; }
    else _value = Invalid;
  }
  HoleClosedValueEnum::operator const char*() const
  {
    switch(_value) {
      case Yes: return "yes";
      case No: return "no";
      case Half: return "half";
      default: break;
    }
    return '\0';
  }
  HoleClosedValueEnum::HoleClosedValueEnum(InnerEnum value): _value(value)
  {
  }
  HoleClosedValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  KindValueEnum::KindValueEnum()
  {
  }
  KindValueEnum::KindValueEnum(const char* value)
  {
    if(strcmp(value, "major")==0) { _value = Major; }
    else if(strcmp(value, "minor")==0) { _value = Minor; }
    else if(strcmp(value, "augmented")==0) { _value = Augmented; }
    else if(strcmp(value, "diminished")==0) { _value = Diminished; }
    else if(strcmp(value, "dominant")==0) { _value = Dominant; }
    else if(strcmp(value, "major-seventh")==0) { _value = MajorSeventh; }
    else if(strcmp(value, "minor-seventh")==0) { _value = MinorSeventh; }
    else if(strcmp(value, "diminished-seventh")==0) { _value = DiminishedSeventh; }
    else if(strcmp(value, "augmented-seventh")==0) { _value = AugmentedSeventh; }
    else if(strcmp(value, "half-diminished")==0) { _value = HalfDiminished; }
    else if(strcmp(value, "major-minor")==0) { _value = MajorMinor; }
    else if(strcmp(value, "major-sixth")==0) { _value = MajorSixth; }
    else if(strcmp(value, "minor-sixth")==0) { _value = MinorSixth; }
    else if(strcmp(value, "dominant-ninth")==0) { _value = DominantNinth; }
    else if(strcmp(value, "major-ninth")==0) { _value = MajorNinth; }
    else if(strcmp(value, "minor-ninth")==0) { _value = MinorNinth; }
    else if(strcmp(value, "dominant-11th")==0) { _value = Dominant11th; }
    else if(strcmp(value, "major-11th")==0) { _value = Major11th; }
    else if(strcmp(value, "minor-11th")==0) { _value = Minor11th; }
    else if(strcmp(value, "dominant-13th")==0) { _value = Dominant13th; }
    else if(strcmp(value, "major-13th")==0) { _value = Major13th; }
    else if(strcmp(value, "minor-13th")==0) { _value = Minor13th; }
    else if(strcmp(value, "suspended-second")==0) { _value = SuspendedSecond; }
    else if(strcmp(value, "suspended-fourth")==0) { _value = SuspendedFourth; }
    else if(strcmp(value, "Neapolitan")==0) { _value = Neapolitan; }
    else if(strcmp(value, "Italian")==0) { _value = Italian; }
    else if(strcmp(value, "French")==0) { _value = French; }
    else if(strcmp(value, "German")==0) { _value = German; }
    else if(strcmp(value, "pedal")==0) { _value = Pedal; }
    else if(strcmp(value, "power")==0) { _value = Power; }
    else if(strcmp(value, "Tristan")==0) { _value = Tristan; }
    else if(strcmp(value, "other")==0) { _value = Other; }
    else if(strcmp(value, "none")==0) { _value = None; }
    else _value = Invalid;
  }
  KindValueEnum::operator const char*() const
  {
    switch(_value) {
      case Major: return "major";
      case Minor: return "minor";
      case Augmented: return "augmented";
      case Diminished: return "diminished";
      case Dominant: return "dominant";
      case MajorSeventh: return "major-seventh";
      case MinorSeventh: return "minor-seventh";
      case DiminishedSeventh: return "diminished-seventh";
      case AugmentedSeventh: return "augmented-seventh";
      case HalfDiminished: return "half-diminished";
      case MajorMinor: return "major-minor";
      case MajorSixth: return "major-sixth";
      case MinorSixth: return "minor-sixth";
      case DominantNinth: return "dominant-ninth";
      case MajorNinth: return "major-ninth";
      case MinorNinth: return "minor-ninth";
      case Dominant11th: return "dominant-11th";
      case Major11th: return "major-11th";
      case Minor11th: return "minor-11th";
      case Dominant13th: return "dominant-13th";
      case Major13th: return "major-13th";
      case Minor13th: return "minor-13th";
      case SuspendedSecond: return "suspended-second";
      case SuspendedFourth: return "suspended-fourth";
      case Neapolitan: return "Neapolitan";
      case Italian: return "Italian";
      case French: return "French";
      case German: return "German";
      case Pedal: return "pedal";
      case Power: return "power";
      case Tristan: return "Tristan";
      case Other: return "other";
      case None: return "none";
      default: break;
    }
    return '\0';
  }
  KindValueEnum::KindValueEnum(InnerEnum value): _value(value)
  {
  }
  KindValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  LeftCenterRightEnum::LeftCenterRightEnum()
  {
  }
  LeftCenterRightEnum::LeftCenterRightEnum(const char* value)
  {
    if(strcmp(value, "left")==0) { _value = Left; }
    else if(strcmp(value, "center")==0) { _value = Center; }
    else if(strcmp(value, "right")==0) { _value = Right; }
    else _value = Invalid;
  }
  LeftCenterRightEnum::operator const char*() const
  {
    switch(_value) {
      case Left: return "left";
      case Center: return "center";
      case Right: return "right";
      default: break;
    }
    return '\0';
  }
  LeftCenterRightEnum::LeftCenterRightEnum(InnerEnum value): _value(value)
  {
  }
  LeftCenterRightEnum::operator InnerEnum() const
  {
    return _value;
  }
  LeftRightEnum::LeftRightEnum()
  {
  }
  LeftRightEnum::LeftRightEnum(const char* value)
  {
    if(strcmp(value, "left")==0) { _value = Left; }
    else if(strcmp(value, "right")==0) { _value = Right; }
    else _value = Invalid;
  }
  LeftRightEnum::operator const char*() const
  {
    switch(_value) {
      case Left: return "left";
      case Right: return "right";
      default: break;
    }
    return '\0';
  }
  LeftRightEnum::LeftRightEnum(InnerEnum value): _value(value)
  {
  }
  LeftRightEnum::operator InnerEnum() const
  {
    return _value;
  }
  LineEndEnum::LineEndEnum()
  {
  }
  LineEndEnum::LineEndEnum(const char* value)
  {
    if(strcmp(value, "up")==0) { _value = Up; }
    else if(strcmp(value, "down")==0) { _value = Down; }
    else if(strcmp(value, "both")==0) { _value = Both; }
    else if(strcmp(value, "arrow")==0) { _value = Arrow; }
    else if(strcmp(value, "none")==0) { _value = None; }
    else _value = Invalid;
  }
  LineEndEnum::operator const char*() const
  {
    switch(_value) {
      case Up: return "up";
      case Down: return "down";
      case Both: return "both";
      case Arrow: return "arrow";
      case None: return "none";
      default: break;
    }
    return '\0';
  }
  LineEndEnum::LineEndEnum(InnerEnum value): _value(value)
  {
  }
  LineEndEnum::operator InnerEnum() const
  {
    return _value;
  }
  LineShapeEnum::LineShapeEnum()
  {
  }
  LineShapeEnum::LineShapeEnum(const char* value)
  {
    if(strcmp(value, "straight")==0) { _value = Straight; }
    else if(strcmp(value, "curved")==0) { _value = Curved; }
    else _value = Invalid;
  }
  LineShapeEnum::operator const char*() const
  {
    switch(_value) {
      case Straight: return "straight";
      case Curved: return "curved";
      default: break;
    }
    return '\0';
  }
  LineShapeEnum::LineShapeEnum(InnerEnum value): _value(value)
  {
  }
  LineShapeEnum::operator InnerEnum() const
  {
    return _value;
  }
  LineTypeEnum::LineTypeEnum()
  {
  }
  LineTypeEnum::LineTypeEnum(const char* value)
  {
    if(strcmp(value, "solid")==0) { _value = Solid; }
    else if(strcmp(value, "dashed")==0) { _value = Dashed; }
    else if(strcmp(value, "dotted")==0) { _value = Dotted; }
    else if(strcmp(value, "wavy")==0) { _value = Wavy; }
    else _value = Invalid;
  }
  LineTypeEnum::operator const char*() const
  {
    switch(_value) {
      case Solid: return "solid";
      case Dashed: return "dashed";
      case Dotted: return "dotted";
      case Wavy: return "wavy";
      default: break;
    }
    return '\0';
  }
  LineTypeEnum::LineTypeEnum(InnerEnum value): _value(value)
  {
  }
  LineTypeEnum::operator InnerEnum() const
  {
    return _value;
  }
  MarginTypeEnum::MarginTypeEnum()
  {
  }
  MarginTypeEnum::MarginTypeEnum(const char* value)
  {
    if(strcmp(value, "odd")==0) { _value = Odd; }
    else if(strcmp(value, "even")==0) { _value = Even; }
    else if(strcmp(value, "both")==0) { _value = Both; }
    else _value = Invalid;
  }
  MarginTypeEnum::operator const char*() const
  {
    switch(_value) {
      case Odd: return "odd";
      case Even: return "even";
      case Both: return "both";
      default: break;
    }
    return '\0';
  }
  MarginTypeEnum::MarginTypeEnum(InnerEnum value): _value(value)
  {
  }
  MarginTypeEnum::operator InnerEnum() const
  {
    return _value;
  }
  MeasureNumberingValueEnum::MeasureNumberingValueEnum()
  {
  }
  MeasureNumberingValueEnum::MeasureNumberingValueEnum(const char* value)
  {
    if(strcmp(value, "none")==0) { _value = None; }
    else if(strcmp(value, "measure")==0) { _value = Measure; }
    else if(strcmp(value, "system")==0) { _value = System; }
    else _value = Invalid;
  }
  MeasureNumberingValueEnum::operator const char*() const
  {
    switch(_value) {
      case None: return "none";
      case Measure: return "measure";
      case System: return "system";
      default: break;
    }
    return '\0';
  }
  MeasureNumberingValueEnum::MeasureNumberingValueEnum(InnerEnum value): _value(value)
  {
  }
  MeasureNumberingValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  MembraneEnum::MembraneEnum()
  {
  }
  MembraneEnum::MembraneEnum(const char* value)
  {
    if(strcmp(value, "bass drum")==0) { _value = BassDrum; }
    else if(strcmp(value, "bass drum on side")==0) { _value = BassDrumOnSide; }
    else if(strcmp(value, "bongos")==0) { _value = Bongos; }
    else if(strcmp(value, "conga drum")==0) { _value = CongaDrum; }
    else if(strcmp(value, "goblet drum")==0) { _value = GobletDrum; }
    else if(strcmp(value, "military drum")==0) { _value = MilitaryDrum; }
    else if(strcmp(value, "snare drum")==0) { _value = SnareDrum; }
    else if(strcmp(value, "snare drum snares off")==0) { _value = SnareDrumSnaresOff; }
    else if(strcmp(value, "tambourine")==0) { _value = Tambourine; }
    else if(strcmp(value, "tenor drum")==0) { _value = TenorDrum; }
    else if(strcmp(value, "timbales")==0) { _value = Timbales; }
    else if(strcmp(value, "tomtom")==0) { _value = Tomtom; }
    else _value = Invalid;
  }
  MembraneEnum::operator const char*() const
  {
    switch(_value) {
      case BassDrum: return "bass drum";
      case BassDrumOnSide: return "bass drum on side";
      case Bongos: return "bongos";
      case CongaDrum: return "conga drum";
      case GobletDrum: return "goblet drum";
      case MilitaryDrum: return "military drum";
      case SnareDrum: return "snare drum";
      case SnareDrumSnaresOff: return "snare drum snares off";
      case Tambourine: return "tambourine";
      case TenorDrum: return "tenor drum";
      case Timbales: return "timbales";
      case Tomtom: return "tomtom";
      default: break;
    }
    return '\0';
  }
  MembraneEnum::MembraneEnum(InnerEnum value): _value(value)
  {
  }
  MembraneEnum::operator InnerEnum() const
  {
    return _value;
  }
  MetalEnum::MetalEnum()
  {
  }
  MetalEnum::MetalEnum(const char* value)
  {
    if(strcmp(value, "almglocken")==0) { _value = Almglocken; }
    else if(strcmp(value, "bell")==0) { _value = Bell; }
    else if(strcmp(value, "bell plate")==0) { _value = BellPlate; }
    else if(strcmp(value, "brake drum")==0) { _value = BrakeDrum; }
    else if(strcmp(value, "Chinese cymbal")==0) { _value = ChineseCymbal; }
    else if(strcmp(value, "cowbell")==0) { _value = Cowbell; }
    else if(strcmp(value, "crash cymbals")==0) { _value = CrashCymbals; }
    else if(strcmp(value, "crotale")==0) { _value = Crotale; }
    else if(strcmp(value, "cymbal tongs")==0) { _value = CymbalTongs; }
    else if(strcmp(value, "domed gong")==0) { _value = DomedGong; }
    else if(strcmp(value, "finger cymbals")==0) { _value = FingerCymbals; }
    else if(strcmp(value, "flexatone")==0) { _value = Flexatone; }
    else if(strcmp(value, "gong")==0) { _value = Gong; }
    else if(strcmp(value, "hi-hat")==0) { _value = HiHat; }
    else if(strcmp(value, "high-hat cymbals")==0) { _value = HighHatCymbals; }
    else if(strcmp(value, "handbell")==0) { _value = Handbell; }
    else if(strcmp(value, "sistrum")==0) { _value = Sistrum; }
    else if(strcmp(value, "sizzle cymbal")==0) { _value = SizzleCymbal; }
    else if(strcmp(value, "sleigh bells")==0) { _value = SleighBells; }
    else if(strcmp(value, "suspended cymbal")==0) { _value = SuspendedCymbal; }
    else if(strcmp(value, "tam tam")==0) { _value = TamTam; }
    else if(strcmp(value, "triangle")==0) { _value = Triangle; }
    else if(strcmp(value, "Vietnamese hat")==0) { _value = VietnameseHat; }
    else _value = Invalid;
  }
  MetalEnum::operator const char*() const
  {
    switch(_value) {
      case Almglocken: return "almglocken";
      case Bell: return "bell";
      case BellPlate: return "bell plate";
      case BrakeDrum: return "brake drum";
      case ChineseCymbal: return "Chinese cymbal";
      case Cowbell: return "cowbell";
      case CrashCymbals: return "crash cymbals";
      case Crotale: return "crotale";
      case CymbalTongs: return "cymbal tongs";
      case DomedGong: return "domed gong";
      case FingerCymbals: return "finger cymbals";
      case Flexatone: return "flexatone";
      case Gong: return "gong";
      case HiHat: return "hi-hat";
      case HighHatCymbals: return "high-hat cymbals";
      case Handbell: return "handbell";
      case Sistrum: return "sistrum";
      case SizzleCymbal: return "sizzle cymbal";
      case SleighBells: return "sleigh bells";
      case SuspendedCymbal: return "suspended cymbal";
      case TamTam: return "tam tam";
      case Triangle: return "triangle";
      case VietnameseHat: return "Vietnamese hat";
      default: break;
    }
    return '\0';
  }
  MetalEnum::MetalEnum(InnerEnum value): _value(value)
  {
  }
  MetalEnum::operator InnerEnum() const
  {
    return _value;
  }
  ModeEnum::ModeEnum()
  {
  }
  ModeEnum::ModeEnum(const char* value)
  {
    if(strcmp(value, "major")==0) { _value = Major; }
    else if(strcmp(value, "minor")==0) { _value = Minor; }
    else if(strcmp(value, "dorian")==0) { _value = Dorian; }
    else if(strcmp(value, "phrygian")==0) { _value = Phrygian; }
    else if(strcmp(value, "lydian")==0) { _value = Lydian; }
    else if(strcmp(value, "mixolydian")==0) { _value = Mixolydian; }
    else if(strcmp(value, "aeolian")==0) { _value = Aeolian; }
    else if(strcmp(value, "ionian")==0) { _value = Ionian; }
    else if(strcmp(value, "locrian")==0) { _value = Locrian; }
    else if(strcmp(value, "none")==0) { _value = None; }
    else _value = Invalid;
  }
  ModeEnum::operator const char*() const
  {
    switch(_value) {
      case Major: return "major";
      case Minor: return "minor";
      case Dorian: return "dorian";
      case Phrygian: return "phrygian";
      case Lydian: return "lydian";
      case Mixolydian: return "mixolydian";
      case Aeolian: return "aeolian";
      case Ionian: return "ionian";
      case Locrian: return "locrian";
      case None: return "none";
      default: break;
    }
    return '\0';
  }
  ModeEnum::ModeEnum(InnerEnum value): _value(value)
  {
  }
  ModeEnum::operator InnerEnum() const
  {
    return _value;
  }
  MuteEnum::MuteEnum()
  {
  }
  MuteEnum::MuteEnum(const char* value)
  {
    if(strcmp(value, "on")==0) { _value = On; }
    else if(strcmp(value, "off")==0) { _value = Off; }
    else if(strcmp(value, "straight")==0) { _value = Straight; }
    else if(strcmp(value, "cup")==0) { _value = Cup; }
    else if(strcmp(value, "harmon-no-stem")==0) { _value = HarmonNoStem; }
    else if(strcmp(value, "harmon-stem")==0) { _value = HarmonStem; }
    else if(strcmp(value, "bucket")==0) { _value = Bucket; }
    else if(strcmp(value, "plunger")==0) { _value = Plunger; }
    else if(strcmp(value, "hat")==0) { _value = Hat; }
    else if(strcmp(value, "solotone")==0) { _value = Solotone; }
    else if(strcmp(value, "practice")==0) { _value = Practice; }
    else if(strcmp(value, "stop-mute")==0) { _value = StopMute; }
    else if(strcmp(value, "stop-hand")==0) { _value = StopHand; }
    else if(strcmp(value, "echo")==0) { _value = Echo; }
    else if(strcmp(value, "palm")==0) { _value = Palm; }
    else _value = Invalid;
  }
  MuteEnum::operator const char*() const
  {
    switch(_value) {
      case On: return "on";
      case Off: return "off";
      case Straight: return "straight";
      case Cup: return "cup";
      case HarmonNoStem: return "harmon-no-stem";
      case HarmonStem: return "harmon-stem";
      case Bucket: return "bucket";
      case Plunger: return "plunger";
      case Hat: return "hat";
      case Solotone: return "solotone";
      case Practice: return "practice";
      case StopMute: return "stop-mute";
      case StopHand: return "stop-hand";
      case Echo: return "echo";
      case Palm: return "palm";
      default: break;
    }
    return '\0';
  }
  MuteEnum::MuteEnum(InnerEnum value): _value(value)
  {
  }
  MuteEnum::operator InnerEnum() const
  {
    return _value;
  }
  NoteheadValueEnum::NoteheadValueEnum()
  {
  }
  NoteheadValueEnum::NoteheadValueEnum(const char* value)
  {
    if(strcmp(value, "slash")==0) { _value = Slash; }
    else if(strcmp(value, "triangle")==0) { _value = Triangle; }
    else if(strcmp(value, "diamond")==0) { _value = Diamond; }
    else if(strcmp(value, "square")==0) { _value = Square; }
    else if(strcmp(value, "cross")==0) { _value = Cross; }
    else if(strcmp(value, "x")==0) { _value = X; }
    else if(strcmp(value, "circle-x")==0) { _value = CircleX; }
    else if(strcmp(value, "inverted triangle")==0) { _value = InvertedTriangle; }
    else if(strcmp(value, "arrow down")==0) { _value = ArrowDown; }
    else if(strcmp(value, "arrow up")==0) { _value = ArrowUp; }
    else if(strcmp(value, "slashed")==0) { _value = Slashed; }
    else if(strcmp(value, "back slashed")==0) { _value = BackSlashed; }
    else if(strcmp(value, "normal")==0) { _value = Normal; }
    else if(strcmp(value, "cluster")==0) { _value = Cluster; }
    else if(strcmp(value, "circle dot")==0) { _value = CircleDot; }
    else if(strcmp(value, "left triangle")==0) { _value = LeftTriangle; }
    else if(strcmp(value, "rectangle")==0) { _value = Rectangle; }
    else if(strcmp(value, "none")==0) { _value = None; }
    else if(strcmp(value, "do")==0) { _value = Do; }
    else if(strcmp(value, "re")==0) { _value = Re; }
    else if(strcmp(value, "mi")==0) { _value = Mi; }
    else if(strcmp(value, "fa")==0) { _value = Fa; }
    else if(strcmp(value, "fa up")==0) { _value = FaUp; }
    else if(strcmp(value, "so")==0) { _value = So; }
    else if(strcmp(value, "la")==0) { _value = La; }
    else if(strcmp(value, "ti")==0) { _value = Ti; }
    else _value = Invalid;
  }
  NoteheadValueEnum::operator const char*() const
  {
    switch(_value) {
      case Slash: return "slash";
      case Triangle: return "triangle";
      case Diamond: return "diamond";
      case Square: return "square";
      case Cross: return "cross";
      case X: return "x";
      case CircleX: return "circle-x";
      case InvertedTriangle: return "inverted triangle";
      case ArrowDown: return "arrow down";
      case ArrowUp: return "arrow up";
      case Slashed: return "slashed";
      case BackSlashed: return "back slashed";
      case Normal: return "normal";
      case Cluster: return "cluster";
      case CircleDot: return "circle dot";
      case LeftTriangle: return "left triangle";
      case Rectangle: return "rectangle";
      case None: return "none";
      case Do: return "do";
      case Re: return "re";
      case Mi: return "mi";
      case Fa: return "fa";
      case FaUp: return "fa up";
      case So: return "so";
      case La: return "la";
      case Ti: return "ti";
      default: break;
    }
    return '\0';
  }
  NoteheadValueEnum::NoteheadValueEnum(InnerEnum value): _value(value)
  {
  }
  NoteheadValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  NoteSizeTypeEnum::NoteSizeTypeEnum()
  {
  }
  NoteSizeTypeEnum::NoteSizeTypeEnum(const char* value)
  {
    if(strcmp(value, "cue")==0) { _value = Cue; }
    else if(strcmp(value, "grace")==0) { _value = Grace; }
    else if(strcmp(value, "large")==0) { _value = Large; }
    else _value = Invalid;
  }
  NoteSizeTypeEnum::operator const char*() const
  {
    switch(_value) {
      case Cue: return "cue";
      case Grace: return "grace";
      case Large: return "large";
      default: break;
    }
    return '\0';
  }
  NoteSizeTypeEnum::NoteSizeTypeEnum(InnerEnum value): _value(value)
  {
  }
  NoteSizeTypeEnum::operator InnerEnum() const
  {
    return _value;
  }
  OnOffEnum::OnOffEnum()
  {
  }
  OnOffEnum::OnOffEnum(const char* value)
  {
    if(strcmp(value, "on")==0) { _value = On; }
    else if(strcmp(value, "off")==0) { _value = Off; }
    else _value = Invalid;
  }
  OnOffEnum::operator const char*() const
  {
    switch(_value) {
      case On: return "on";
      case Off: return "off";
      default: break;
    }
    return '\0';
  }
  OnOffEnum::OnOffEnum(InnerEnum value): _value(value)
  {
  }
  OnOffEnum::operator InnerEnum() const
  {
    return _value;
  }
  OverUnderEnum::OverUnderEnum()
  {
  }
  OverUnderEnum::OverUnderEnum(const char* value)
  {
    if(strcmp(value, "over")==0) { _value = Over; }
    else if(strcmp(value, "under")==0) { _value = Under; }
    else _value = Invalid;
  }
  OverUnderEnum::operator const char*() const
  {
    switch(_value) {
      case Over: return "over";
      case Under: return "under";
      default: break;
    }
    return '\0';
  }
  OverUnderEnum::OverUnderEnum(InnerEnum value): _value(value)
  {
  }
  OverUnderEnum::operator InnerEnum() const
  {
    return _value;
  }
  PitchedEnum::PitchedEnum()
  {
  }
  PitchedEnum::PitchedEnum(const char* value)
  {
    if(strcmp(value, "chimes")==0) { _value = Chimes; }
    else if(strcmp(value, "glockenspiel")==0) { _value = Glockenspiel; }
    else if(strcmp(value, "mallet")==0) { _value = Mallet; }
    else if(strcmp(value, "marimba")==0) { _value = Marimba; }
    else if(strcmp(value, "tubular chimes")==0) { _value = TubularChimes; }
    else if(strcmp(value, "vibraphone")==0) { _value = Vibraphone; }
    else if(strcmp(value, "xylophone")==0) { _value = Xylophone; }
    else _value = Invalid;
  }
  PitchedEnum::operator const char*() const
  {
    switch(_value) {
      case Chimes: return "chimes";
      case Glockenspiel: return "glockenspiel";
      case Mallet: return "mallet";
      case Marimba: return "marimba";
      case TubularChimes: return "tubular chimes";
      case Vibraphone: return "vibraphone";
      case Xylophone: return "xylophone";
      default: break;
    }
    return '\0';
  }
  PitchedEnum::PitchedEnum(InnerEnum value): _value(value)
  {
  }
  PitchedEnum::operator InnerEnum() const
  {
    return _value;
  }
  PrincipalVoiceSymbolEnum::PrincipalVoiceSymbolEnum()
  {
  }
  PrincipalVoiceSymbolEnum::PrincipalVoiceSymbolEnum(const char* value)
  {
    if(strcmp(value, "Hauptstimme")==0) { _value = Hauptstimme; }
    else if(strcmp(value, "Nebenstimme")==0) { _value = Nebenstimme; }
    else if(strcmp(value, "plain")==0) { _value = Plain; }
    else if(strcmp(value, "none")==0) { _value = None; }
    else _value = Invalid;
  }
  PrincipalVoiceSymbolEnum::operator const char*() const
  {
    switch(_value) {
      case Hauptstimme: return "Hauptstimme";
      case Nebenstimme: return "Nebenstimme";
      case Plain: return "plain";
      case None: return "none";
      default: break;
    }
    return '\0';
  }
  PrincipalVoiceSymbolEnum::PrincipalVoiceSymbolEnum(InnerEnum value): _value(value)
  {
  }
  PrincipalVoiceSymbolEnum::operator InnerEnum() const
  {
    return _value;
  }
  RightLeftMiddleEnum::RightLeftMiddleEnum()
  {
  }
  RightLeftMiddleEnum::RightLeftMiddleEnum(const char* value)
  {
    if(strcmp(value, "right")==0) { _value = Right; }
    else if(strcmp(value, "left")==0) { _value = Left; }
    else if(strcmp(value, "middle")==0) { _value = Middle; }
    else _value = Invalid;
  }
  RightLeftMiddleEnum::operator const char*() const
  {
    switch(_value) {
      case Right: return "right";
      case Left: return "left";
      case Middle: return "middle";
      default: break;
    }
    return '\0';
  }
  RightLeftMiddleEnum::RightLeftMiddleEnum(InnerEnum value): _value(value)
  {
  }
  RightLeftMiddleEnum::operator InnerEnum() const
  {
    return _value;
  }
  SemiPitchedEnum::SemiPitchedEnum()
  {
  }
  SemiPitchedEnum::SemiPitchedEnum(const char* value)
  {
    if(strcmp(value, "high")==0) { _value = High; }
    else if(strcmp(value, "medium-high")==0) { _value = MediumHigh; }
    else if(strcmp(value, "medium")==0) { _value = Medium; }
    else if(strcmp(value, "medium-low")==0) { _value = MediumLow; }
    else if(strcmp(value, "low")==0) { _value = Low; }
    else if(strcmp(value, "very-low")==0) { _value = VeryLow; }
    else _value = Invalid;
  }
  SemiPitchedEnum::operator const char*() const
  {
    switch(_value) {
      case High: return "high";
      case MediumHigh: return "medium-high";
      case Medium: return "medium";
      case MediumLow: return "medium-low";
      case Low: return "low";
      case VeryLow: return "very-low";
      default: break;
    }
    return '\0';
  }
  SemiPitchedEnum::SemiPitchedEnum(InnerEnum value): _value(value)
  {
  }
  SemiPitchedEnum::operator InnerEnum() const
  {
    return _value;
  }
  ShowFretsEnum::ShowFretsEnum()
  {
  }
  ShowFretsEnum::ShowFretsEnum(const char* value)
  {
    if(strcmp(value, "numbers")==0) { _value = Numbers; }
    else if(strcmp(value, "letters")==0) { _value = Letters; }
    else _value = Invalid;
  }
  ShowFretsEnum::operator const char*() const
  {
    switch(_value) {
      case Numbers: return "numbers";
      case Letters: return "letters";
      default: break;
    }
    return '\0';
  }
  ShowFretsEnum::ShowFretsEnum(InnerEnum value): _value(value)
  {
  }
  ShowFretsEnum::operator InnerEnum() const
  {
    return _value;
  }
  ShowTupletEnum::ShowTupletEnum()
  {
  }
  ShowTupletEnum::ShowTupletEnum(const char* value)
  {
    if(strcmp(value, "actual")==0) { _value = Actual; }
    else if(strcmp(value, "both")==0) { _value = Both; }
    else if(strcmp(value, "none")==0) { _value = None; }
    else _value = Invalid;
  }
  ShowTupletEnum::operator const char*() const
  {
    switch(_value) {
      case Actual: return "actual";
      case Both: return "both";
      case None: return "none";
      default: break;
    }
    return '\0';
  }
  ShowTupletEnum::ShowTupletEnum(InnerEnum value): _value(value)
  {
  }
  ShowTupletEnum::operator InnerEnum() const
  {
    return _value;
  }
  StaffTypeEnum::StaffTypeEnum()
  {
  }
  StaffTypeEnum::StaffTypeEnum(const char* value)
  {
    if(strcmp(value, "ossia")==0) { _value = Ossia; }
    else if(strcmp(value, "cue")==0) { _value = Cue; }
    else if(strcmp(value, "editorial")==0) { _value = Editorial; }
    else if(strcmp(value, "regular")==0) { _value = Regular; }
    else if(strcmp(value, "alternate")==0) { _value = Alternate; }
    else _value = Invalid;
  }
  StaffTypeEnum::operator const char*() const
  {
    switch(_value) {
      case Ossia: return "ossia";
      case Cue: return "cue";
      case Editorial: return "editorial";
      case Regular: return "regular";
      case Alternate: return "alternate";
      default: break;
    }
    return '\0';
  }
  StaffTypeEnum::StaffTypeEnum(InnerEnum value): _value(value)
  {
  }
  StaffTypeEnum::operator InnerEnum() const
  {
    return _value;
  }
  StartNoteEnum::StartNoteEnum()
  {
  }
  StartNoteEnum::StartNoteEnum(const char* value)
  {
    if(strcmp(value, "upper")==0) { _value = Upper; }
    else if(strcmp(value, "main")==0) { _value = Main; }
    else if(strcmp(value, "below")==0) { _value = Below; }
    else _value = Invalid;
  }
  StartNoteEnum::operator const char*() const
  {
    switch(_value) {
      case Upper: return "upper";
      case Main: return "main";
      case Below: return "below";
      default: break;
    }
    return '\0';
  }
  StartNoteEnum::StartNoteEnum(InnerEnum value): _value(value)
  {
  }
  StartNoteEnum::operator InnerEnum() const
  {
    return _value;
  }
  StartStopChangeContinueEnum::StartStopChangeContinueEnum()
  {
  }
  StartStopChangeContinueEnum::StartStopChangeContinueEnum(const char* value)
  {
    if(strcmp(value, "start")==0) { _value = Start; }
    else if(strcmp(value, "stop")==0) { _value = Stop; }
    else if(strcmp(value, "change")==0) { _value = Change; }
    else if(strcmp(value, "continue")==0) { _value = Continue; }
    else _value = Invalid;
  }
  StartStopChangeContinueEnum::operator const char*() const
  {
    switch(_value) {
      case Start: return "start";
      case Stop: return "stop";
      case Change: return "change";
      case Continue: return "continue";
      default: break;
    }
    return '\0';
  }
  StartStopChangeContinueEnum::StartStopChangeContinueEnum(InnerEnum value): _value(value)
  {
  }
  StartStopChangeContinueEnum::operator InnerEnum() const
  {
    return _value;
  }
  StartStopContinueEnum::StartStopContinueEnum()
  {
  }
  StartStopContinueEnum::StartStopContinueEnum(const char* value)
  {
    if(strcmp(value, "start")==0) { _value = Start; }
    else if(strcmp(value, "stop")==0) { _value = Stop; }
    else if(strcmp(value, "continue")==0) { _value = Continue; }
    else _value = Invalid;
  }
  StartStopContinueEnum::operator const char*() const
  {
    switch(_value) {
      case Start: return "start";
      case Stop: return "stop";
      case Continue: return "continue";
      default: break;
    }
    return '\0';
  }
  StartStopContinueEnum::StartStopContinueEnum(InnerEnum value): _value(value)
  {
  }
  StartStopContinueEnum::operator InnerEnum() const
  {
    return _value;
  }
  StartStopDiscontinueEnum::StartStopDiscontinueEnum()
  {
  }
  StartStopDiscontinueEnum::StartStopDiscontinueEnum(const char* value)
  {
    if(strcmp(value, "start")==0) { _value = Start; }
    else if(strcmp(value, "stop")==0) { _value = Stop; }
    else if(strcmp(value, "discontinue")==0) { _value = Discontinue; }
    else _value = Invalid;
  }
  StartStopDiscontinueEnum::operator const char*() const
  {
    switch(_value) {
      case Start: return "start";
      case Stop: return "stop";
      case Discontinue: return "discontinue";
      default: break;
    }
    return '\0';
  }
  StartStopDiscontinueEnum::StartStopDiscontinueEnum(InnerEnum value): _value(value)
  {
  }
  StartStopDiscontinueEnum::operator InnerEnum() const
  {
    return _value;
  }
  StartStopSingleEnum::StartStopSingleEnum()
  {
  }
  StartStopSingleEnum::StartStopSingleEnum(const char* value)
  {
    if(strcmp(value, "start")==0) { _value = Start; }
    else if(strcmp(value, "stop")==0) { _value = Stop; }
    else if(strcmp(value, "single")==0) { _value = Single; }
    else _value = Invalid;
  }
  StartStopSingleEnum::operator const char*() const
  {
    switch(_value) {
      case Start: return "start";
      case Stop: return "stop";
      case Single: return "single";
      default: break;
    }
    return '\0';
  }
  StartStopSingleEnum::StartStopSingleEnum(InnerEnum value): _value(value)
  {
  }
  StartStopSingleEnum::operator InnerEnum() const
  {
    return _value;
  }
  StartStopEnum::StartStopEnum()
  {
  }
  StartStopEnum::StartStopEnum(const char* value)
  {
    if(strcmp(value, "start")==0) { _value = Start; }
    else if(strcmp(value, "stop")==0) { _value = Stop; }
    else _value = Invalid;
  }
  StartStopEnum::operator const char*() const
  {
    switch(_value) {
      case Start: return "start";
      case Stop: return "stop";
      default: break;
    }
    return '\0';
  }
  StartStopEnum::StartStopEnum(InnerEnum value): _value(value)
  {
  }
  StartStopEnum::operator InnerEnum() const
  {
    return _value;
  }
  StemValueEnum::StemValueEnum()
  {
  }
  StemValueEnum::StemValueEnum(const char* value)
  {
    if(strcmp(value, "down")==0) { _value = Down; }
    else if(strcmp(value, "up")==0) { _value = Up; }
    else if(strcmp(value, "double")==0) { _value = Double; }
    else if(strcmp(value, "none")==0) { _value = None; }
    else _value = Invalid;
  }
  StemValueEnum::operator const char*() const
  {
    switch(_value) {
      case Down: return "down";
      case Up: return "up";
      case Double: return "double";
      case None: return "none";
      default: break;
    }
    return '\0';
  }
  StemValueEnum::StemValueEnum(InnerEnum value): _value(value)
  {
  }
  StemValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  StepEnum::StepEnum()
  {
  }
  StepEnum::StepEnum(const char* value)
  {
    if(strcmp(value, "A")==0) { _value = A; }
    else if(strcmp(value, "B")==0) { _value = B; }
    else if(strcmp(value, "C")==0) { _value = C; }
    else if(strcmp(value, "D")==0) { _value = D; }
    else if(strcmp(value, "E")==0) { _value = E; }
    else if(strcmp(value, "F")==0) { _value = F; }
    else if(strcmp(value, "G")==0) { _value = G; }
    else _value = Invalid;
  }
  StepEnum::operator const char*() const
  {
    switch(_value) {
      case A: return "A";
      case B: return "B";
      case C: return "C";
      case D: return "D";
      case E: return "E";
      case F: return "F";
      case G: return "G";
      default: break;
    }
    return '\0';
  }
  StepEnum::StepEnum(InnerEnum value): _value(value)
  {
  }
  StepEnum::operator InnerEnum() const
  {
    return _value;
  }
  StickLocationEnum::StickLocationEnum()
  {
  }
  StickLocationEnum::StickLocationEnum(const char* value)
  {
    if(strcmp(value, "center")==0) { _value = Center; }
    else if(strcmp(value, "rim")==0) { _value = Rim; }
    else if(strcmp(value, "cymbal bell")==0) { _value = CymbalBell; }
    else if(strcmp(value, "cymbal edge")==0) { _value = CymbalEdge; }
    else _value = Invalid;
  }
  StickLocationEnum::operator const char*() const
  {
    switch(_value) {
      case Center: return "center";
      case Rim: return "rim";
      case CymbalBell: return "cymbal bell";
      case CymbalEdge: return "cymbal edge";
      default: break;
    }
    return '\0';
  }
  StickLocationEnum::StickLocationEnum(InnerEnum value): _value(value)
  {
  }
  StickLocationEnum::operator InnerEnum() const
  {
    return _value;
  }
  StickMaterialEnum::StickMaterialEnum()
  {
  }
  StickMaterialEnum::StickMaterialEnum(const char* value)
  {
    if(strcmp(value, "soft")==0) { _value = Soft; }
    else if(strcmp(value, "medium")==0) { _value = Medium; }
    else if(strcmp(value, "hard")==0) { _value = Hard; }
    else if(strcmp(value, "shaded")==0) { _value = Shaded; }
    else if(strcmp(value, "x")==0) { _value = X; }
    else _value = Invalid;
  }
  StickMaterialEnum::operator const char*() const
  {
    switch(_value) {
      case Soft: return "soft";
      case Medium: return "medium";
      case Hard: return "hard";
      case Shaded: return "shaded";
      case X: return "x";
      default: break;
    }
    return '\0';
  }
  StickMaterialEnum::StickMaterialEnum(InnerEnum value): _value(value)
  {
  }
  StickMaterialEnum::operator InnerEnum() const
  {
    return _value;
  }
  StickTypeEnum::StickTypeEnum()
  {
  }
  StickTypeEnum::StickTypeEnum(const char* value)
  {
    if(strcmp(value, "bass drum")==0) { _value = BassDrum; }
    else if(strcmp(value, "double bass drum")==0) { _value = DoubleBassDrum; }
    else if(strcmp(value, "timpani")==0) { _value = Timpani; }
    else if(strcmp(value, "xylophone")==0) { _value = Xylophone; }
    else if(strcmp(value, "yarn")==0) { _value = Yarn; }
    else _value = Invalid;
  }
  StickTypeEnum::operator const char*() const
  {
    switch(_value) {
      case BassDrum: return "bass drum";
      case DoubleBassDrum: return "double bass drum";
      case Timpani: return "timpani";
      case Xylophone: return "xylophone";
      case Yarn: return "yarn";
      default: break;
    }
    return '\0';
  }
  StickTypeEnum::StickTypeEnum(InnerEnum value): _value(value)
  {
  }
  StickTypeEnum::operator InnerEnum() const
  {
    return _value;
  }
  SyllabicEnum::SyllabicEnum()
  {
  }
  SyllabicEnum::SyllabicEnum(const char* value)
  {
    if(strcmp(value, "single")==0) { _value = Single; }
    else if(strcmp(value, "begin")==0) { _value = Begin; }
    else if(strcmp(value, "end")==0) { _value = End; }
    else if(strcmp(value, "middle")==0) { _value = Middle; }
    else _value = Invalid;
  }
  SyllabicEnum::operator const char*() const
  {
    switch(_value) {
      case Single: return "single";
      case Begin: return "begin";
      case End: return "end";
      case Middle: return "middle";
      default: break;
    }
    return '\0';
  }
  SyllabicEnum::SyllabicEnum(InnerEnum value): _value(value)
  {
  }
  SyllabicEnum::operator InnerEnum() const
  {
    return _value;
  }
  SymbolSizeEnum::SymbolSizeEnum()
  {
  }
  SymbolSizeEnum::SymbolSizeEnum(const char* value)
  {
    if(strcmp(value, "full")==0) { _value = Full; }
    else if(strcmp(value, "cue")==0) { _value = Cue; }
    else if(strcmp(value, "large")==0) { _value = Large; }
    else _value = Invalid;
  }
  SymbolSizeEnum::operator const char*() const
  {
    switch(_value) {
      case Full: return "full";
      case Cue: return "cue";
      case Large: return "large";
      default: break;
    }
    return '\0';
  }
  SymbolSizeEnum::SymbolSizeEnum(InnerEnum value): _value(value)
  {
  }
  SymbolSizeEnum::operator InnerEnum() const
  {
    return _value;
  }
  TextDirectionEnum::TextDirectionEnum()
  {
  }
  TextDirectionEnum::TextDirectionEnum(const char* value)
  {
    if(strcmp(value, "ltr")==0) { _value = Ltr; }
    else if(strcmp(value, "rtl")==0) { _value = Rtl; }
    else if(strcmp(value, "lro")==0) { _value = Lro; }
    else if(strcmp(value, "rlo")==0) { _value = Rlo; }
    else _value = Invalid;
  }
  TextDirectionEnum::operator const char*() const
  {
    switch(_value) {
      case Ltr: return "ltr";
      case Rtl: return "rtl";
      case Lro: return "lro";
      case Rlo: return "rlo";
      default: break;
    }
    return '\0';
  }
  TextDirectionEnum::TextDirectionEnum(InnerEnum value): _value(value)
  {
  }
  TextDirectionEnum::operator InnerEnum() const
  {
    return _value;
  }
  TimeRelationEnum::TimeRelationEnum()
  {
  }
  TimeRelationEnum::TimeRelationEnum(const char* value)
  {
    if(strcmp(value, "parentheses")==0) { _value = Parentheses; }
    else if(strcmp(value, "bracket")==0) { _value = Bracket; }
    else if(strcmp(value, "equals")==0) { _value = Equals; }
    else if(strcmp(value, "slash")==0) { _value = Slash; }
    else if(strcmp(value, "space")==0) { _value = Space; }
    else if(strcmp(value, "hyphen")==0) { _value = Hyphen; }
    else _value = Invalid;
  }
  TimeRelationEnum::operator const char*() const
  {
    switch(_value) {
      case Parentheses: return "parentheses";
      case Bracket: return "bracket";
      case Equals: return "equals";
      case Slash: return "slash";
      case Space: return "space";
      case Hyphen: return "hyphen";
      default: break;
    }
    return '\0';
  }
  TimeRelationEnum::TimeRelationEnum(InnerEnum value): _value(value)
  {
  }
  TimeRelationEnum::operator InnerEnum() const
  {
    return _value;
  }
  TimeSeparatorEnum::TimeSeparatorEnum()
  {
  }
  TimeSeparatorEnum::TimeSeparatorEnum(const char* value)
  {
    if(strcmp(value, "none")==0) { _value = None; }
    else if(strcmp(value, "horizontal")==0) { _value = Horizontal; }
    else if(strcmp(value, "diagonal")==0) { _value = Diagonal; }
    else if(strcmp(value, "vertical")==0) { _value = Vertical; }
    else if(strcmp(value, "adjacent")==0) { _value = Adjacent; }
    else _value = Invalid;
  }
  TimeSeparatorEnum::operator const char*() const
  {
    switch(_value) {
      case None: return "none";
      case Horizontal: return "horizontal";
      case Diagonal: return "diagonal";
      case Vertical: return "vertical";
      case Adjacent: return "adjacent";
      default: break;
    }
    return '\0';
  }
  TimeSeparatorEnum::TimeSeparatorEnum(InnerEnum value): _value(value)
  {
  }
  TimeSeparatorEnum::operator InnerEnum() const
  {
    return _value;
  }
  TimeSymbolEnum::TimeSymbolEnum()
  {
  }
  TimeSymbolEnum::TimeSymbolEnum(const char* value)
  {
    if(strcmp(value, "common")==0) { _value = Common; }
    else if(strcmp(value, "cut")==0) { _value = Cut; }
    else if(strcmp(value, "single-number")==0) { _value = SingleNumber; }
    else if(strcmp(value, "note")==0) { _value = Note; }
    else if(strcmp(value, "dotted-note")==0) { _value = DottedNote; }
    else if(strcmp(value, "normal")==0) { _value = Normal; }
    else _value = Invalid;
  }
  TimeSymbolEnum::operator const char*() const
  {
    switch(_value) {
      case Common: return "common";
      case Cut: return "cut";
      case SingleNumber: return "single-number";
      case Note: return "note";
      case DottedNote: return "dotted-note";
      case Normal: return "normal";
      default: break;
    }
    return '\0';
  }
  TimeSymbolEnum::TimeSymbolEnum(InnerEnum value): _value(value)
  {
  }
  TimeSymbolEnum::operator InnerEnum() const
  {
    return _value;
  }
  TipDirectionEnum::TipDirectionEnum()
  {
  }
  TipDirectionEnum::TipDirectionEnum(const char* value)
  {
    if(strcmp(value, "up")==0) { _value = Up; }
    else if(strcmp(value, "down")==0) { _value = Down; }
    else if(strcmp(value, "left")==0) { _value = Left; }
    else if(strcmp(value, "right")==0) { _value = Right; }
    else if(strcmp(value, "northwest")==0) { _value = Northwest; }
    else if(strcmp(value, "northeast")==0) { _value = Northeast; }
    else if(strcmp(value, "southeast")==0) { _value = Southeast; }
    else if(strcmp(value, "southwest")==0) { _value = Southwest; }
    else _value = Invalid;
  }
  TipDirectionEnum::operator const char*() const
  {
    switch(_value) {
      case Up: return "up";
      case Down: return "down";
      case Left: return "left";
      case Right: return "right";
      case Northwest: return "northwest";
      case Northeast: return "northeast";
      case Southeast: return "southeast";
      case Southwest: return "southwest";
      default: break;
    }
    return '\0';
  }
  TipDirectionEnum::TipDirectionEnum(InnerEnum value): _value(value)
  {
  }
  TipDirectionEnum::operator InnerEnum() const
  {
    return _value;
  }
  TopBottomEnum::TopBottomEnum()
  {
  }
  TopBottomEnum::TopBottomEnum(const char* value)
  {
    if(strcmp(value, "top")==0) { _value = Top; }
    else if(strcmp(value, "bottom")==0) { _value = Bottom; }
    else _value = Invalid;
  }
  TopBottomEnum::operator const char*() const
  {
    switch(_value) {
      case Top: return "top";
      case Bottom: return "bottom";
      default: break;
    }
    return '\0';
  }
  TopBottomEnum::TopBottomEnum(InnerEnum value): _value(value)
  {
  }
  TopBottomEnum::operator InnerEnum() const
  {
    return _value;
  }
  TrillStepEnum::TrillStepEnum()
  {
  }
  TrillStepEnum::TrillStepEnum(const char* value)
  {
    if(strcmp(value, "whole")==0) { _value = Whole; }
    else if(strcmp(value, "half")==0) { _value = Half; }
    else if(strcmp(value, "unison")==0) { _value = Unison; }
    else _value = Invalid;
  }
  TrillStepEnum::operator const char*() const
  {
    switch(_value) {
      case Whole: return "whole";
      case Half: return "half";
      case Unison: return "unison";
      default: break;
    }
    return '\0';
  }
  TrillStepEnum::TrillStepEnum(InnerEnum value): _value(value)
  {
  }
  TrillStepEnum::operator InnerEnum() const
  {
    return _value;
  }
  TwoNoteTurnEnum::TwoNoteTurnEnum()
  {
  }
  TwoNoteTurnEnum::TwoNoteTurnEnum(const char* value)
  {
    if(strcmp(value, "whole")==0) { _value = Whole; }
    else if(strcmp(value, "half")==0) { _value = Half; }
    else if(strcmp(value, "none")==0) { _value = None; }
    else _value = Invalid;
  }
  TwoNoteTurnEnum::operator const char*() const
  {
    switch(_value) {
      case Whole: return "whole";
      case Half: return "half";
      case None: return "none";
      default: break;
    }
    return '\0';
  }
  TwoNoteTurnEnum::TwoNoteTurnEnum(InnerEnum value): _value(value)
  {
  }
  TwoNoteTurnEnum::operator InnerEnum() const
  {
    return _value;
  }
  UpDownStopContinueEnum::UpDownStopContinueEnum()
  {
  }
  UpDownStopContinueEnum::UpDownStopContinueEnum(const char* value)
  {
    if(strcmp(value, "up")==0) { _value = Up; }
    else if(strcmp(value, "down")==0) { _value = Down; }
    else if(strcmp(value, "stop")==0) { _value = Stop; }
    else if(strcmp(value, "continue")==0) { _value = Continue; }
    else _value = Invalid;
  }
  UpDownStopContinueEnum::operator const char*() const
  {
    switch(_value) {
      case Up: return "up";
      case Down: return "down";
      case Stop: return "stop";
      case Continue: return "continue";
      default: break;
    }
    return '\0';
  }
  UpDownStopContinueEnum::UpDownStopContinueEnum(InnerEnum value): _value(value)
  {
  }
  UpDownStopContinueEnum::operator InnerEnum() const
  {
    return _value;
  }
  UpDownEnum::UpDownEnum()
  {
  }
  UpDownEnum::UpDownEnum(const char* value)
  {
    if(strcmp(value, "up")==0) { _value = Up; }
    else if(strcmp(value, "down")==0) { _value = Down; }
    else _value = Invalid;
  }
  UpDownEnum::operator const char*() const
  {
    switch(_value) {
      case Up: return "up";
      case Down: return "down";
      default: break;
    }
    return '\0';
  }
  UpDownEnum::UpDownEnum(InnerEnum value): _value(value)
  {
  }
  UpDownEnum::operator InnerEnum() const
  {
    return _value;
  }
  UprightInvertedEnum::UprightInvertedEnum()
  {
  }
  UprightInvertedEnum::UprightInvertedEnum(const char* value)
  {
    if(strcmp(value, "upright")==0) { _value = Upright; }
    else if(strcmp(value, "inverted")==0) { _value = Inverted; }
    else _value = Invalid;
  }
  UprightInvertedEnum::operator const char*() const
  {
    switch(_value) {
      case Upright: return "upright";
      case Inverted: return "inverted";
      default: break;
    }
    return '\0';
  }
  UprightInvertedEnum::UprightInvertedEnum(InnerEnum value): _value(value)
  {
  }
  UprightInvertedEnum::operator InnerEnum() const
  {
    return _value;
  }
  ValignImageEnum::ValignImageEnum()
  {
  }
  ValignImageEnum::ValignImageEnum(const char* value)
  {
    if(strcmp(value, "top")==0) { _value = Top; }
    else if(strcmp(value, "middle")==0) { _value = Middle; }
    else if(strcmp(value, "bottom")==0) { _value = Bottom; }
    else _value = Invalid;
  }
  ValignImageEnum::operator const char*() const
  {
    switch(_value) {
      case Top: return "top";
      case Middle: return "middle";
      case Bottom: return "bottom";
      default: break;
    }
    return '\0';
  }
  ValignImageEnum::ValignImageEnum(InnerEnum value): _value(value)
  {
  }
  ValignImageEnum::operator InnerEnum() const
  {
    return _value;
  }
  ValignEnum::ValignEnum()
  {
  }
  ValignEnum::ValignEnum(const char* value)
  {
    if(strcmp(value, "top")==0) { _value = Top; }
    else if(strcmp(value, "middle")==0) { _value = Middle; }
    else if(strcmp(value, "bottom")==0) { _value = Bottom; }
    else if(strcmp(value, "baseline")==0) { _value = Baseline; }
    else _value = Invalid;
  }
  ValignEnum::operator const char*() const
  {
    switch(_value) {
      case Top: return "top";
      case Middle: return "middle";
      case Bottom: return "bottom";
      case Baseline: return "baseline";
      default: break;
    }
    return '\0';
  }
  ValignEnum::ValignEnum(InnerEnum value): _value(value)
  {
  }
  ValignEnum::operator InnerEnum() const
  {
    return _value;
  }
  WedgeTypeEnum::WedgeTypeEnum()
  {
  }
  WedgeTypeEnum::WedgeTypeEnum(const char* value)
  {
    if(strcmp(value, "crescendo")==0) { _value = Crescendo; }
    else if(strcmp(value, "diminuendo")==0) { _value = Diminuendo; }
    else if(strcmp(value, "stop")==0) { _value = Stop; }
    else if(strcmp(value, "continue")==0) { _value = Continue; }
    else _value = Invalid;
  }
  WedgeTypeEnum::operator const char*() const
  {
    switch(_value) {
      case Crescendo: return "crescendo";
      case Diminuendo: return "diminuendo";
      case Stop: return "stop";
      case Continue: return "continue";
      default: break;
    }
    return '\0';
  }
  WedgeTypeEnum::WedgeTypeEnum(InnerEnum value): _value(value)
  {
  }
  WedgeTypeEnum::operator InnerEnum() const
  {
    return _value;
  }
  WingedEnum::WingedEnum()
  {
  }
  WingedEnum::WingedEnum(const char* value)
  {
    if(strcmp(value, "none")==0) { _value = None; }
    else if(strcmp(value, "straight")==0) { _value = Straight; }
    else if(strcmp(value, "curved")==0) { _value = Curved; }
    else if(strcmp(value, "double-straight")==0) { _value = DoubleStraight; }
    else if(strcmp(value, "double-curved")==0) { _value = DoubleCurved; }
    else _value = Invalid;
  }
  WingedEnum::operator const char*() const
  {
    switch(_value) {
      case None: return "none";
      case Straight: return "straight";
      case Curved: return "curved";
      case DoubleStraight: return "double-straight";
      case DoubleCurved: return "double-curved";
      default: break;
    }
    return '\0';
  }
  WingedEnum::WingedEnum(InnerEnum value): _value(value)
  {
  }
  WingedEnum::operator InnerEnum() const
  {
    return _value;
  }
  WoodEnum::WoodEnum()
  {
  }
  WoodEnum::WoodEnum(const char* value)
  {
    if(strcmp(value, "board clapper")==0) { _value = BoardClapper; }
    else if(strcmp(value, "cabasa")==0) { _value = Cabasa; }
    else if(strcmp(value, "castanets")==0) { _value = Castanets; }
    else if(strcmp(value, "claves")==0) { _value = Claves; }
    else if(strcmp(value, "guiro")==0) { _value = Guiro; }
    else if(strcmp(value, "log drum")==0) { _value = LogDrum; }
    else if(strcmp(value, "maraca")==0) { _value = Maraca; }
    else if(strcmp(value, "maracas")==0) { _value = Maracas; }
    else if(strcmp(value, "ratchet")==0) { _value = Ratchet; }
    else if(strcmp(value, "sandpaper blocks")==0) { _value = SandpaperBlocks; }
    else if(strcmp(value, "slit drum")==0) { _value = SlitDrum; }
    else if(strcmp(value, "temple block")==0) { _value = TempleBlock; }
    else if(strcmp(value, "vibraslap")==0) { _value = Vibraslap; }
    else if(strcmp(value, "wood block")==0) { _value = WoodBlock; }
    else _value = Invalid;
  }
  WoodEnum::operator const char*() const
  {
    switch(_value) {
      case BoardClapper: return "board clapper";
      case Cabasa: return "cabasa";
      case Castanets: return "castanets";
      case Claves: return "claves";
      case Guiro: return "guiro";
      case LogDrum: return "log drum";
      case Maraca: return "maraca";
      case Maracas: return "maracas";
      case Ratchet: return "ratchet";
      case SandpaperBlocks: return "sandpaper blocks";
      case SlitDrum: return "slit drum";
      case TempleBlock: return "temple block";
      case Vibraslap: return "vibraslap";
      case WoodBlock: return "wood block";
      default: break;
    }
    return '\0';
  }
  WoodEnum::WoodEnum(InnerEnum value): _value(value)
  {
  }
  WoodEnum::operator InnerEnum() const
  {
    return _value;
  }
  YesNoEnum::YesNoEnum()
  {
  }
  YesNoEnum::YesNoEnum(const char* value)
  {
    if(strcmp(value, "yes")==0) { _value = Yes; }
    else if(strcmp(value, "no")==0) { _value = No; }
    else _value = Invalid;
  }
  YesNoEnum::operator const char*() const
  {
    switch(_value) {
      case Yes: return "yes";
      case No: return "no";
      default: break;
    }
    return '\0';
  }
  YesNoEnum::YesNoEnum(InnerEnum value): _value(value)
  {
  }
  YesNoEnum::operator InnerEnum() const
  {
    return _value;
  }
  BreathMarkValueEnum::BreathMarkValueEnum()
  {
  }
  BreathMarkValueEnum::BreathMarkValueEnum(const char* value)
  {
    if(strcmp(value, "")==0) { _value = Empty; }
    else if(strcmp(value, "comma")==0) { _value = Comma; }
    else if(strcmp(value, "tick")==0) { _value = Tick; }
    else _value = Invalid;
  }
  BreathMarkValueEnum::operator const char*() const
  {
    switch(_value) {
      case Empty: return "";
      case Comma: return "comma";
      case Tick: return "tick";
      default: break;
    }
    return '\0';
  }
  BreathMarkValueEnum::BreathMarkValueEnum(InnerEnum value): _value(value)
  {
  }
  BreathMarkValueEnum::operator InnerEnum() const
  {
    return _value;
  }
  FermataShapeEnum::FermataShapeEnum()
  {
  }
  FermataShapeEnum::FermataShapeEnum(const char* value)
  {
    if(strcmp(value, "normal")==0) { _value = Normal; }
    else if(strcmp(value, "angled")==0) { _value = Angled; }
    else if(strcmp(value, "square")==0) { _value = Square; }
    else if(strcmp(value, "")==0) { _value = Empty; }
    else _value = Invalid;
  }
  FermataShapeEnum::operator const char*() const
  {
    switch(_value) {
      case Normal: return "normal";
      case Angled: return "angled";
      case Square: return "square";
      case Empty: return "";
      default: break;
    }
    return '\0';
  }
  FermataShapeEnum::FermataShapeEnum(InnerEnum value): _value(value)
  {
  }
  FermataShapeEnum::operator InnerEnum() const
  {
    return _value;
  }
  FontSizeEnum::FontSizeEnum()
  {
  }
  FontSizeEnum::FontSizeEnum(const char* value)
  {
    if(strcmp(value, "xx-small")==0) { _value = XxSmall; }
    else if(strcmp(value, "x-small")==0) { _value = XSmall; }
    else if(strcmp(value, "small")==0) { _value = Small; }
    else if(strcmp(value, "medium")==0) { _value = Medium; }
    else if(strcmp(value, "large")==0) { _value = Large; }
    else if(strcmp(value, "x-large")==0) { _value = XLarge; }
    else if(strcmp(value, "xx-large")==0) { _value = XxLarge; }
    else {
      char* endptr;
      _number = (float)strtod(value, &endptr);
      if(!strlen(endptr)) _value = Number;
      else _value = Invalid;
    }
  }
  FontSizeEnum::operator const char*() const
  {
    switch(_value) {
      case XxSmall: return "xx-small";
      case XSmall: return "x-small";
      case Small: return "small";
      case Medium: return "medium";
      case Large: return "large";
      case XLarge: return "x-large";
      case XxLarge: return "xx-large";
      case Number: {
        memset(_str, 0, 15);
        snprintf(_str, sizeof(_str), "%.3f", _number);
        while(((_str[strlen(_str)-1]=='0')&&(strchr(_str,'.')))||_str[strlen(_str)-1]=='.')_str[strlen(_str)-1]='\0';
        return _str;
      }
      default: break;
    }
    return '\0';
  }
  FontSizeEnum::FontSizeEnum(InnerEnum value): _value(value)
  {
  }
  FontSizeEnum::operator InnerEnum() const
  {
    return _value;
  }
  FontSizeEnum::FontSizeEnum(float value): _value(Number), _number(value)
  {
  }
  FontSizeEnum::operator float() const
  {
    return _number;
  }
  NoteTypeValueEnum::NoteTypeValueEnum()
  {
  }
  NoteTypeValueEnum::NoteTypeValueEnum(const char* value)
  {
    if(strcmp(value, "1024th")==0) { _value = OneThousandTwentyFourth; }
    else if(strcmp(value, "512th")==0) { _value = FiveHundredTwelfth; }
    else if(strcmp(value, "256th")==0) { _value = TwoHundredFifthySixth; }
    else if(strcmp(value, "128th")==0) { _value = OneHundredTwentyEighth; }
    else if(strcmp(value, "64th")==0) { _value = SixtyFourth; }
    else if(strcmp(value, "32nd")==0) { _value = ThirtySecond; }
    else if(strcmp(value, "16th")==0) { _value = Sixteenth; }
    else if(strcmp(value, "eighth")==0) { _value = Eighth; }
    else if(strcmp(value, "quarter")==0) { _value = Quarter; }
    else if(strcmp(value, "half")==0) { _value = Half; }
    else if(strcmp(value, "whole")==0) { _value = Whole; }
    else if(strcmp(value, "breve")==0) { _value = Breve; }
    else if(strcmp(value, "long")==0) { _value = Long; }
    else if(strcmp(value, "maxima")==0) { _value = Maxima; }
    else _value = Invalid;
  }
  NoteTypeValueEnum::operator const char*() const
  {
    switch(_value) {
      case OneThousandTwentyFourth: return "1024th";
      case FiveHundredTwelfth: return "512th";
      case TwoHundredFifthySixth: return "256th";
      case OneHundredTwentyEighth: return "128th";
      case SixtyFourth: return "64th";
      case ThirtySecond: return "32nd";
      case Sixteenth: return "16th";
      case Eighth: return "eighth";
      case Quarter: return "quarter";
      case Half: return "half";
      case Whole: return "whole";
      case Breve: return "breve";
      case Long: return "long";
      case Maxima: return "maxima";
      default: break;
    }
    return '\0';
  }
  NoteTypeValueEnum::NoteTypeValueEnum(InnerEnum value): _value(value)
  {
  }  
  NoteTypeValueEnum::operator InnerEnum() const
  {
    return _value;
  }  
  NumberOrNormalEnum::NumberOrNormalEnum()
  {
  }
  NumberOrNormalEnum::NumberOrNormalEnum(const char* value)
  {
    if(strcmp(value, "normal")==0) { _value = Normal; }
    else {
      char* endptr;
      _number = (float)strtod(value, &endptr);
      if(!strlen(endptr)) _value = Number;
      else _value = Invalid;
    }
  }
  NumberOrNormalEnum::operator const char*() const
  {
    switch(_value) {
      case Normal: return "normal";
      case Number: {
        memset(_str, 0, 15);
        snprintf(_str, sizeof(_str), "%.3f", _number);
        while(((_str[strlen(_str)-1]=='0')&&(strchr(_str,'.')))||_str[strlen(_str)-1]=='.')_str[strlen(_str)-1]='\0';
        return _str;
      }
      default: break;
    }
    return '\0';
  }
  NumberOrNormalEnum::NumberOrNormalEnum(InnerEnum value): _value(value)
  {
  }    
  NumberOrNormalEnum::operator InnerEnum() const
  {
    return _value;
  }
  NumberOrNormalEnum::NumberOrNormalEnum(float value): _value(Number), _number(value)
  {
  }   
  NumberOrNormalEnum::operator float() const
  {
    return _number;
  }
  PositiveIntegerOrEmptyEnum::PositiveIntegerOrEmptyEnum(): _value(Empty)
  {
  }
  PositiveIntegerOrEmptyEnum::PositiveIntegerOrEmptyEnum(const char* value)
  {
    if(strcmp(value, "")==0) { _value = Empty; }
    else {
      char* endptr;
      _number = (int)strtol(value, &endptr, 10);
      if(!strlen(endptr)) _value = Number;
      else _value = Invalid;
    }
  }
  PositiveIntegerOrEmptyEnum::operator const char*() const
  {
    switch(_value) {
      case Empty: return "";
      case Number: {
        memset(_str, 0, 10);
        snprintf(_str, sizeof(_str), "%d", _number);
        return _str;
      }
      default: break;
    }
    return '\0';
  }
  PositiveIntegerOrEmptyEnum::PositiveIntegerOrEmptyEnum(InnerEnum value): _value(value)
  {
  }    
  PositiveIntegerOrEmptyEnum::operator InnerEnum() const
  {
    return _value;
  }
  PositiveIntegerOrEmptyEnum::PositiveIntegerOrEmptyEnum(int value): _value(Number), _number(value)
  {
  }
  PositiveIntegerOrEmptyEnum::operator int() const
  {
    return _number;
  }
  YesNoNumberEnum::YesNoNumberEnum()
  {
  }
  YesNoNumberEnum::YesNoNumberEnum(const char* value)
  {
    if(strcmp(value, "yes")==0) { _value = Yes; }
    else if(strcmp(value, "no")==0) { _value = No; }
    else {
      char* endptr;
      _number = (float)strtod(value, &endptr);
      if(!strlen(endptr)) _value = Number;
      else _value = Invalid;
    }
  }
  YesNoNumberEnum::operator const char*() const
  {
    switch(_value) {
      case Yes: return "yes";
      case No: return "no";
      case Number: {
        memset(_str, 0, 15);
        snprintf(_str, sizeof(_str), "%.3f", _number);
        while(((_str[strlen(_str)-1]=='0')&&(strchr(_str,'.')))||_str[strlen(_str)-1]=='.')_str[strlen(_str)-1]='\0';
        return _str;
      }
      default: break;
    }
    return '\0';
  }
  YesNoNumberEnum::YesNoNumberEnum(InnerEnum value): _value(value)
  {
  }    
  YesNoNumberEnum::operator InnerEnum() const
  {
    return _value;
  }
  YesNoNumberEnum::YesNoNumberEnum(float value): _value(Number), _number(value)
  {
  }  
  YesNoNumberEnum::operator float() const
  {
    return _number;
  }
}
