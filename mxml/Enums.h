#ifndef ENUMS_H
#define ENUMS_H

namespace mxml
{
  class AboveBelowEnum
  {
  public:
    typedef enum {Invalid, Above, Below} InnerEnum;
    AboveBelowEnum();
    AboveBelowEnum(const char* value);
    operator const char*() const;
    AboveBelowEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class AccidentalValueEnum
  {
  public:
    typedef enum {Invalid, Sharp, Natural, Flat, DoubleSharp, SharpSharp, FlatFlat, NaturalSharp, NaturalFlat, QuarterFlat, QuarterSharp, ThreeQuartersFlat, ThreeQuartersSharp, SharpDown, SharpUp, NaturalDown, NaturalUp, FlatDown, FlatUp, TripleSharp, TripleFlat, SlashQuarterSharp, SlashSharp, SlashFlat, DoubleSlashFlat, Sharp1, Sharp2, Sharp3, Sharp5, Flat1, Flat2, Flat3, Flat4, Sori, Koron} InnerEnum;
    AccidentalValueEnum();
    AccidentalValueEnum(const char* value);
    operator const char*() const;
    AccidentalValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class ArrowDirectionEnum
  {
  public:
    typedef enum {Invalid, Left, Up, Right, Down, Northwest, Northeast, Southeast, Southwest, LeftRight, UpDown, NorthwestSoutheast, NortheastSouthwest, Other} InnerEnum;
    ArrowDirectionEnum();
    ArrowDirectionEnum(const char* value);
    operator const char*() const;
    ArrowDirectionEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class ArrowStyleEnum
  {
  public:
    typedef enum {Invalid, Single, Double, Filled, Hollow, Paired, Combined, Other} InnerEnum;
    ArrowStyleEnum();
    ArrowStyleEnum(const char* value);
    operator const char*() const;
    ArrowStyleEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class BackwardForwardEnum
  {
  public:
    typedef enum {Invalid, Backward, Forward} InnerEnum;
    BackwardForwardEnum();
    BackwardForwardEnum(const char* value);
    operator const char*() const;
    BackwardForwardEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class BarStyleEnum
  {
  public:
    typedef enum {Invalid, Regular, Dotted, Dashed, Heavy, LightLight, LightHeavy, HeavyLight, HeavyHeavy, Tick, Short, None} InnerEnum;
    BarStyleEnum();
    BarStyleEnum(const char* value);
    operator const char*() const;
    BarStyleEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class BeamValueEnum
  {
  public:
    typedef enum {Invalid, Begin, Continue, End, ForwardHook, BackwardHook} InnerEnum;
    BeamValueEnum();
    BeamValueEnum(const char* value);
    operator const char*() const;
    BeamValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class BeaterValueEnum
  {
  public:
    typedef enum {Invalid, Bow, ChimeHammer, Coin, Finger, Fingernail, Fist, GuiroScraper, Hammer, Hand, JazzStick, KnittingNeedle, MetalHammer, SnareStick, SpoonMallet, TriangleBeater, TriangleBeaterPlain, WireBrush} InnerEnum;
    BeaterValueEnum();
    BeaterValueEnum(const char* value);
    operator const char*() const;
    BeaterValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class CancelLocationEnum
  {
  public:
    typedef enum {Invalid, Left, Right, BeforeBarline} InnerEnum;
    CancelLocationEnum();
    CancelLocationEnum(const char* value);
    operator const char*() const;
    CancelLocationEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class CircularArrowEnum
  {
  public:
    typedef enum {Invalid, Clockwise, Anticlockwise} InnerEnum;
    CircularArrowEnum();
    CircularArrowEnum(const char* value);
    operator const char*() const;
    CircularArrowEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class ClefSignEnum
  {
  public:
    typedef enum {Invalid=6, G=7, F=5, C=0, Percussion, TAB, Jianpu, None} InnerEnum;
    ClefSignEnum();
    ClefSignEnum(const char* value);
    operator const char*() const;
    ClefSignEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class CssFontSizeEnum
  {
  public:
    typedef enum {Invalid, XxSmall, XSmall, Small, Medium, Large, XLarge, XxLarge} InnerEnum;
    CssFontSizeEnum();
    CssFontSizeEnum(const char* value);
    operator const char*() const;
    CssFontSizeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class DegreeSymbolValueEnum
  {
  public:
    typedef enum {Invalid, Major, Minor, Augmented, Diminished, HalfDiminished} InnerEnum;
    DegreeSymbolValueEnum();
    DegreeSymbolValueEnum(const char* value);
    operator const char*() const;
    DegreeSymbolValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class DegreeTypeValueEnum
  {
  public:
    typedef enum {Invalid, Add, Alter, Subtract} InnerEnum;
    DegreeTypeValueEnum();
    DegreeTypeValueEnum(const char* value);
    operator const char*() const;
    DegreeTypeValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class EffectEnum
  {
  public:
    typedef enum {Invalid, Anvil, AutoHorn, BirdWhistle, Cannon, DuckCall, GunShot, KlaxonHorn, LionsRoar, PoliceWhistle, Siren, SlideWhistle, ThunderSheet, WindMachine, WindWhistle} InnerEnum;
    EffectEnum();
    EffectEnum(const char* value);
    operator const char*() const;
    EffectEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class EnclosureShapeEnum
  {
  public:
    typedef enum {Invalid, Rectangle, Square, Oval, Circle, Bracket, Triangle, Diamond, None} InnerEnum;
    EnclosureShapeEnum();
    EnclosureShapeEnum(const char* value);
    operator const char*() const;
    EnclosureShapeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class FanEnum
  {
  public:
    typedef enum {Invalid, Accel, Rit, None} InnerEnum;
    FanEnum();
    FanEnum(const char* value);
    operator const char*() const;
    FanEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class FontStyleEnum
  {
  public:
    typedef enum {Invalid, Normal, Italic} InnerEnum;
    FontStyleEnum();
    FontStyleEnum(const char* value);
    operator const char*() const;
    FontStyleEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class FontWeightEnum
  {
  public:
    typedef enum {Invalid, Normal, Bold} InnerEnum;
    FontWeightEnum();
    FontWeightEnum(const char* value);
    operator const char*() const;
    FontWeightEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class GlassEnum
  {
  public:
    typedef enum {Invalid, WindChimes} InnerEnum;
    GlassEnum();
    GlassEnum(const char* value);
    operator const char*() const;
    GlassEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class GroupBarlineValueEnum
  {
  public:
    typedef enum {Invalid, Yes, No, Mensurstrich} InnerEnum;
    GroupBarlineValueEnum();
    GroupBarlineValueEnum(const char* value);
    operator const char*() const;
    GroupBarlineValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class GroupSymbolValueEnum
  {
  public:
    typedef enum {Invalid, None, Brace, Line, Bracket, Square} InnerEnum;
    GroupSymbolValueEnum();
    GroupSymbolValueEnum(const char* value);
    operator const char*() const;
    GroupSymbolValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class HandbellValueEnum
  {
  public:
    typedef enum {Invalid, Damp, Echo, Gyro, HandMartellato, MalletLift, MalletTable, Martellato, MartellatoLift, MutedMartellato, PluckLift, Swing} InnerEnum;
    HandbellValueEnum();
    HandbellValueEnum(const char* value);
    operator const char*() const;
    HandbellValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class HarmonyTypeEnum
  {
  public:
    typedef enum {Invalid, Explicit, Implied, Alternate} InnerEnum;
    HarmonyTypeEnum();
    HarmonyTypeEnum(const char* value);
    operator const char*() const;
    HarmonyTypeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class HoleClosedLocationEnum
  {
  public:
    typedef enum {Invalid, Right, Bottom, Left, Top} InnerEnum;
    HoleClosedLocationEnum();
    HoleClosedLocationEnum(const char* value);
    operator const char*() const;
    HoleClosedLocationEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class HoleClosedValueEnum
  {
  public:
    typedef enum {Invalid, Yes, No, Half} InnerEnum;
    HoleClosedValueEnum();
    HoleClosedValueEnum(const char* value);
    operator const char*() const;
    HoleClosedValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class KindValueEnum
  {
  public:
    typedef enum {Invalid, Major, Minor, Augmented, Diminished, Dominant, MajorSeventh, MinorSeventh, DiminishedSeventh, AugmentedSeventh, HalfDiminished, MajorMinor, MajorSixth, MinorSixth, DominantNinth, MajorNinth, MinorNinth, Dominant11th, Major11th, Minor11th, Dominant13th, Major13th, Minor13th, SuspendedSecond, SuspendedFourth, Neapolitan, Italian, French, German, Pedal, Power, Tristan, Other, None} InnerEnum;
    KindValueEnum();
    KindValueEnum(const char* value);
    operator const char*() const;
    KindValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class LeftCenterRightEnum
  {
  public:
    typedef enum {Invalid, Left, Center, Right} InnerEnum;
    LeftCenterRightEnum();
    LeftCenterRightEnum(const char* value);
    operator const char*() const;
    LeftCenterRightEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class LeftRightEnum
  {
  public:
    typedef enum {Invalid, Left, Right} InnerEnum;
    LeftRightEnum();
    LeftRightEnum(const char* value);
    operator const char*() const;
    LeftRightEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class LineEndEnum
  {
  public:
    typedef enum {Invalid, Up, Down, Both, Arrow, None} InnerEnum;
    LineEndEnum();
    LineEndEnum(const char* value);
    operator const char*() const;
    LineEndEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class LineShapeEnum
  {
  public:
    typedef enum {Invalid, Straight, Curved} InnerEnum;
    LineShapeEnum();
    LineShapeEnum(const char* value);
    operator const char*() const;
    LineShapeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class LineTypeEnum
  {
  public:
    typedef enum {Invalid, Solid, Dashed, Dotted, Wavy} InnerEnum;
    LineTypeEnum();
    LineTypeEnum(const char* value);
    operator const char*() const;
    LineTypeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class MarginTypeEnum
  {
  public:
    typedef enum {Invalid, Odd, Even, Both} InnerEnum;
    MarginTypeEnum();
    MarginTypeEnum(const char* value);
    operator const char*() const;
    MarginTypeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class MeasureNumberingValueEnum
  {
  public:
    typedef enum {Invalid, None, Measure, System} InnerEnum;
    MeasureNumberingValueEnum();
    MeasureNumberingValueEnum(const char* value);
    operator const char*() const;
    MeasureNumberingValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class MembraneEnum
  {
  public:
    typedef enum {Invalid, BassDrum, BassDrumOnSide, Bongos, CongaDrum, GobletDrum, MilitaryDrum, SnareDrum, SnareDrumSnaresOff, Tambourine, TenorDrum, Timbales, Tomtom} InnerEnum;
    MembraneEnum();
    MembraneEnum(const char* value);
    operator const char*() const;
    MembraneEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class MetalEnum
  {
  public:
    typedef enum {Invalid, Almglocken, Bell, BellPlate, BrakeDrum, ChineseCymbal, Cowbell, CrashCymbals, Crotale, CymbalTongs, DomedGong, FingerCymbals, Flexatone, Gong, HiHat, HighHatCymbals, Handbell, Sistrum, SizzleCymbal, SleighBells, SuspendedCymbal, TamTam, Triangle, VietnameseHat} InnerEnum;
    MetalEnum();
    MetalEnum(const char* value);
    operator const char*() const;
    MetalEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class ModeEnum
  {
  public:
    typedef enum {Invalid, Major, Minor, Dorian, Phrygian, Lydian, Mixolydian, Aeolian, Ionian, Locrian, None} InnerEnum;
    ModeEnum();
    ModeEnum(const char* value);
    operator const char*() const;
    ModeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class MuteEnum
  {
  public:
    typedef enum {Invalid, On, Off, Straight, Cup, HarmonNoStem, HarmonStem, Bucket, Plunger, Hat, Solotone, Practice, StopMute, StopHand, Echo, Palm} InnerEnum;
    MuteEnum();
    MuteEnum(const char* value);
    operator const char*() const;
    MuteEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class NoteheadValueEnum
  {
  public:
    typedef enum {Invalid, Slash, Triangle, Diamond, Square, Cross, X, CircleX, InvertedTriangle, ArrowDown, ArrowUp, Slashed, BackSlashed, Normal, Cluster, CircleDot, LeftTriangle, Rectangle, None, Do, Re, Mi, Fa, FaUp, So, La, Ti} InnerEnum;
    NoteheadValueEnum();
    NoteheadValueEnum(const char* value);
    operator const char*() const;
    NoteheadValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class NoteSizeTypeEnum
  {
  public:
    typedef enum {Invalid, Cue, Grace, Large} InnerEnum;
    NoteSizeTypeEnum();
    NoteSizeTypeEnum(const char* value);
    operator const char*() const;
    NoteSizeTypeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class OnOffEnum
  {
  public:
    typedef enum {Invalid, On, Off} InnerEnum;
    OnOffEnum();
    OnOffEnum(const char* value);
    operator const char*() const;
    OnOffEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class OverUnderEnum
  {
  public:
    typedef enum {Invalid, Over, Under} InnerEnum;
    OverUnderEnum();
    OverUnderEnum(const char* value);
    operator const char*() const;
    OverUnderEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class PitchedEnum
  {
  public:
    typedef enum {Invalid, Chimes, Glockenspiel, Mallet, Marimba, TubularChimes, Vibraphone, Xylophone} InnerEnum;
    PitchedEnum();
    PitchedEnum(const char* value);
    operator const char*() const;
    PitchedEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class PrincipalVoiceSymbolEnum
  {
  public:
    typedef enum {Invalid, Hauptstimme, Nebenstimme, Plain, None} InnerEnum;
    PrincipalVoiceSymbolEnum();
    PrincipalVoiceSymbolEnum(const char* value);
    operator const char*() const;
    PrincipalVoiceSymbolEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class RightLeftMiddleEnum
  {
  public:
    typedef enum {Invalid, Right, Left, Middle} InnerEnum;
    RightLeftMiddleEnum();
    RightLeftMiddleEnum(const char* value);
    operator const char*() const;
    RightLeftMiddleEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class SemiPitchedEnum
  {
  public:
    typedef enum {Invalid, High, MediumHigh, Medium, MediumLow, Low, VeryLow} InnerEnum;
    SemiPitchedEnum();
    SemiPitchedEnum(const char* value);
    operator const char*() const;
    SemiPitchedEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class ShowFretsEnum
  {
  public:
    typedef enum {Invalid, Numbers, Letters} InnerEnum;
    ShowFretsEnum();
    ShowFretsEnum(const char* value);
    operator const char*() const;
    ShowFretsEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class ShowTupletEnum
  {
  public:
    typedef enum {Invalid, Actual, Both, None} InnerEnum;
    ShowTupletEnum();
    ShowTupletEnum(const char* value);
    operator const char*() const;
    ShowTupletEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class StaffTypeEnum
  {
  public:
    typedef enum {Invalid, Ossia, Cue, Editorial, Regular, Alternate} InnerEnum;
    StaffTypeEnum();
    StaffTypeEnum(const char* value);
    operator const char*() const;
    StaffTypeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class StartNoteEnum
  {
  public:
    typedef enum {Invalid, Upper, Main, Below} InnerEnum;
    StartNoteEnum();
    StartNoteEnum(const char* value);
    operator const char*() const;
    StartNoteEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class StartStopChangeContinueEnum
  {
  public:
    typedef enum {Invalid, Start, Stop, Change, Continue} InnerEnum;
    StartStopChangeContinueEnum();
    StartStopChangeContinueEnum(const char* value);
    operator const char*() const;
    StartStopChangeContinueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class StartStopContinueEnum
  {
  public:
    typedef enum {Invalid, Start, Stop, Continue} InnerEnum;
    StartStopContinueEnum();
    StartStopContinueEnum(const char* value);
    operator const char*() const;
    StartStopContinueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class StartStopDiscontinueEnum
  {
  public:
    typedef enum {Invalid, Start, Stop, Discontinue} InnerEnum;
    StartStopDiscontinueEnum();
    StartStopDiscontinueEnum(const char* value);
    operator const char*() const;
    StartStopDiscontinueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class StartStopSingleEnum
  {
  public:
    typedef enum {Invalid, Start, Stop, Single} InnerEnum;
    StartStopSingleEnum();
    StartStopSingleEnum(const char* value);
    operator const char*() const;
    StartStopSingleEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class StartStopEnum
  {
  public:
    typedef enum {Invalid, Start, Stop} InnerEnum;
    StartStopEnum();
    StartStopEnum(const char* value);
    operator const char*() const;
    StartStopEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class StemValueEnum
  {
  public:
    typedef enum {Invalid, Down, Up, Double, None} InnerEnum;
    StemValueEnum();
    StemValueEnum(const char* value);
    operator const char*() const;
    StemValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class StepEnum
  {
  public:
    typedef enum {Invalid=12, A=9, B=11, C=0, D=2, E=4, F=5, G=7} InnerEnum;
    StepEnum();
    StepEnum(const char* value);
    operator const char*() const;
    StepEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class StickLocationEnum
  {
  public:
    typedef enum {Invalid, Center, Rim, CymbalBell, CymbalEdge} InnerEnum;
    StickLocationEnum();
    StickLocationEnum(const char* value);
    operator const char*() const;
    StickLocationEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class StickMaterialEnum
  {
  public:
    typedef enum {Invalid, Soft, Medium, Hard, Shaded, X} InnerEnum;
    StickMaterialEnum();
    StickMaterialEnum(const char* value);
    operator const char*() const;
    StickMaterialEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class StickTypeEnum
  {
  public:
    typedef enum {Invalid, BassDrum, DoubleBassDrum, Timpani, Xylophone, Yarn} InnerEnum;
    StickTypeEnum();
    StickTypeEnum(const char* value);
    operator const char*() const;
    StickTypeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class SyllabicEnum
  {
  public:
    typedef enum {Invalid, Single, Begin, End, Middle} InnerEnum;
    SyllabicEnum();
    SyllabicEnum(const char* value);
    operator const char*() const;
    SyllabicEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class SymbolSizeEnum
  {
  public:
    typedef enum {Invalid, Full, Cue, Large} InnerEnum;
    SymbolSizeEnum();
    SymbolSizeEnum(const char* value);
    operator const char*() const;
    SymbolSizeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class TextDirectionEnum
  {
  public:
    typedef enum {Invalid, Ltr, Rtl, Lro, Rlo} InnerEnum;
    TextDirectionEnum();
    TextDirectionEnum(const char* value);
    operator const char*() const;
    TextDirectionEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class TimeRelationEnum
  {
  public:
    typedef enum {Invalid, Parentheses, Bracket, Equals, Slash, Space, Hyphen} InnerEnum;
    TimeRelationEnum();
    TimeRelationEnum(const char* value);
    operator const char*() const;
    TimeRelationEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class TimeSeparatorEnum
  {
  public:
    typedef enum {Invalid, None, Horizontal, Diagonal, Vertical, Adjacent} InnerEnum;
    TimeSeparatorEnum();
    TimeSeparatorEnum(const char* value);
    operator const char*() const;
    TimeSeparatorEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class TimeSymbolEnum
  {
  public:
    typedef enum {Invalid, Common, Cut, SingleNumber, Note, DottedNote, Normal} InnerEnum;
    TimeSymbolEnum();
    TimeSymbolEnum(const char* value);
    operator const char*() const;
    TimeSymbolEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class TipDirectionEnum
  {
  public:
    typedef enum {Invalid, Up, Down, Left, Right, Northwest, Northeast, Southeast, Southwest} InnerEnum;
    TipDirectionEnum();
    TipDirectionEnum(const char* value);
    operator const char*() const;
    TipDirectionEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class TopBottomEnum
  {
  public:
    typedef enum {Invalid, Top, Bottom} InnerEnum;
    TopBottomEnum();
    TopBottomEnum(const char* value);
    operator const char*() const;
    TopBottomEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class TrillStepEnum
  {
  public:
    typedef enum {Invalid, Whole, Half, Unison} InnerEnum;
    TrillStepEnum();
    TrillStepEnum(const char* value);
    operator const char*() const;
    TrillStepEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class TwoNoteTurnEnum
  {
  public:
    typedef enum {Invalid, Whole, Half, None} InnerEnum;
    TwoNoteTurnEnum();
    TwoNoteTurnEnum(const char* value);
    operator const char*() const;
    TwoNoteTurnEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class UpDownStopContinueEnum
  {
  public:
    typedef enum {Invalid, Up, Down, Stop, Continue} InnerEnum;
    UpDownStopContinueEnum();
    UpDownStopContinueEnum(const char* value);
    operator const char*() const;
    UpDownStopContinueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class UpDownEnum
  {
  public:
    typedef enum {Invalid, Up, Down} InnerEnum;
    UpDownEnum();
    UpDownEnum(const char* value);
    operator const char*() const;
    UpDownEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class UprightInvertedEnum
  {
  public:
    typedef enum {Invalid, Upright, Inverted} InnerEnum;
    UprightInvertedEnum();
    UprightInvertedEnum(const char* value);
    operator const char*() const;
    UprightInvertedEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class ValignImageEnum
  {
  public:
    typedef enum {Invalid, Top, Middle, Bottom} InnerEnum;
    ValignImageEnum();
    ValignImageEnum(const char* value);
    operator const char*() const;
    ValignImageEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class ValignEnum
  {
  public:
    typedef enum {Invalid, Top, Middle, Bottom, Baseline} InnerEnum;
    ValignEnum();
    ValignEnum(const char* value);
    operator const char*() const;
    ValignEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class WedgeTypeEnum
  {
  public:
    typedef enum {Invalid, Crescendo, Diminuendo, Stop, Continue} InnerEnum;
    WedgeTypeEnum();
    WedgeTypeEnum(const char* value);
    operator const char*() const;
    WedgeTypeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class WingedEnum
  {
  public:
    typedef enum {Invalid, None, Straight, Curved, DoubleStraight, DoubleCurved} InnerEnum;
    WingedEnum();
    WingedEnum(const char* value);
    operator const char*() const;
    WingedEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class WoodEnum
  {
  public:
    typedef enum {Invalid, BoardClapper, Cabasa, Castanets, Claves, Guiro, LogDrum, Maraca, Maracas, Ratchet, SandpaperBlocks, SlitDrum, TempleBlock, Vibraslap, WoodBlock} InnerEnum;
    WoodEnum();
    WoodEnum(const char* value);
    operator const char*() const;
    WoodEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class YesNoEnum
  {
  public:
    typedef enum {Invalid, Yes, No} InnerEnum;
    YesNoEnum();
    YesNoEnum(const char* value);
    operator const char*() const;
    YesNoEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class BreathMarkValueEnum
  {
  public:
    typedef enum {Invalid, Empty, Comma, Tick} InnerEnum;
    BreathMarkValueEnum();
    BreathMarkValueEnum(const char* value);
    operator const char*() const;
    BreathMarkValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class FermataShapeEnum
  {
  public:
    typedef enum {Invalid, Normal, Angled, Square, Empty} InnerEnum;
    FermataShapeEnum();
    FermataShapeEnum(const char* value);
    operator const char*() const;
    FermataShapeEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class FontSizeEnum
  {
  public:
    typedef enum {Invalid, XxSmall, XSmall, Small, Medium, Large, XLarge, XxLarge, Number} InnerEnum;
    FontSizeEnum();
    FontSizeEnum(const char* value);
    operator const char*() const;
    FontSizeEnum(InnerEnum value);
    operator InnerEnum() const;
    FontSizeEnum(float value);
    operator float() const;
  private:
    InnerEnum _value {Invalid};
    float _number {0};
    mutable char _str[15];
  };
  class NoteTypeValueEnum
  {
  public:
    typedef enum {Invalid, OneThousandTwentyFourth, FiveHundredTwelfth, TwoHundredFifthySixth, OneHundredTwentyEighth, SixtyFourth, ThirtySecond, Sixteenth, Eighth, Quarter, Half, Whole, Breve, Long, Maxima } InnerEnum;
    NoteTypeValueEnum();
    NoteTypeValueEnum(const char* value);
    operator const char*() const;
    NoteTypeValueEnum(InnerEnum value);
    operator InnerEnum() const;
  private:
    InnerEnum _value {Invalid};
  };
  class NumberOrNormalEnum
  {
  public:
    typedef enum {Invalid, Number, Normal} InnerEnum;     
    NumberOrNormalEnum();
    NumberOrNormalEnum(const char* value);
    operator const char*() const; 
    NumberOrNormalEnum(InnerEnum value);
    operator InnerEnum() const;
    NumberOrNormalEnum(float value);
    operator float() const;    
  private:
    InnerEnum _value {Invalid};
    float _number {0};
    mutable char _str[15];
  };
  class PositiveIntegerOrEmptyEnum
  {
  public:
    typedef enum {Invalid, Number, Empty} InnerEnum;   
    PositiveIntegerOrEmptyEnum();
    PositiveIntegerOrEmptyEnum(const char* value);
    operator const char*() const;
    PositiveIntegerOrEmptyEnum(InnerEnum value);       
    operator InnerEnum() const;
    PositiveIntegerOrEmptyEnum(int value);
    operator int() const;  
  private:
    InnerEnum _value {Invalid};
    int _number {0};
    mutable char _str[11];
  };
  class YesNoNumberEnum
  {
  public:
    typedef enum {Invalid, Yes, No, Number} InnerEnum;    
    YesNoNumberEnum();
    YesNoNumberEnum(const char* value);
    operator const char*() const;  
    YesNoNumberEnum(InnerEnum value);       
    operator InnerEnum() const;
    YesNoNumberEnum(float value);
    operator float() const;     
  private:
    InnerEnum _value {Invalid};
    float _number {0};
    mutable char _str[15];
  };
}
#endif //ENUMS_H
