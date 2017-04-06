#-------------------------------------------------
#
# Project created by QtCreator 2017-03-27T16:27:16
#
#-------------------------------------------------

QT       += core gui
QT       += svg
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mgraph
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


OBJECTS += \
    ../mxml/pugixml.o \
    ../mxml/AccidentalMark.o \
    ../mxml/Accidental.o \
    ../mxml/AccidentalText.o \
    ../mxml/AccordionRegistration.o \
    ../mxml/Accord.o \
    ../mxml/Appearance.o \
    ../mxml/Arpeggiate.o \
    ../mxml/Arrow.o \
    ../mxml/Articulations.o \
    ../mxml/Attributes.o \
    ../mxml/Backup.o \
    ../mxml/Barline.o \
    ../mxml/Barre.o \
    ../mxml/BarStyleColor.o \
    ../mxml/BassAlter.o \
    ../mxml/Bass.o \
    ../mxml/BassStep.o \
    ../mxml/Beam.o \
    ../mxml/Beater.o \
    ../mxml/BeatRepeat.o \
    ../mxml/Bend.o \
    ../mxml/BendSound.o \
    ../mxml/Bezier.o \
    ../mxml/Bookmark.o \
    ../mxml/Bracket.o \
    ../mxml/BreathMark.o \
    ../mxml/Cancel.o \
    ../mxml/Clef.o \
    ../mxml/Color.o \
    ../mxml/Credit.o \
    ../mxml/DashedFormatting.o \
    ../mxml/Dashes.o \
    ../mxml/Defaults.o \
    ../mxml/DegreeAlter.o \
    ../mxml/Degree.o \
    ../mxml/DegreeType.o \
    ../mxml/DegreeValue.o \
    ../mxml/Direction.o \
    ../mxml/DirectionType.o \
    ../mxml/Directive.o \
    ../mxml/Distance.o \
    ../mxml/DocumentAttributes.o \
    ../mxml/DocumentPartwise.o \
    ../mxml/Dynamics.o \
    ../mxml/Element.o \
    ../mxml/ElementPosition.o \
    ../mxml/EmptyFont.o \
    ../mxml/EmptyLine.o \
    ../mxml/EmptyPlacement.o \
    ../mxml/EmptyPrintObjectStyleAlign.o \
    ../mxml/EmptyPrintStyleAlign.o \
    ../mxml/EmptyPrintStyle.o \
    ../mxml/EmptyTrillSound.o \
    ../mxml/Enclosure.o \
    ../mxml/Ending.o \
    ../mxml/Enums.o \
    ../mxml/Extend.o \
    ../mxml/Feature.o \
    ../mxml/Fermata.o \
    ../mxml/FiguredBass.o \
    ../mxml/Figure.o \
    ../mxml/Fingering.o \
    ../mxml/FirstFret.o \
    ../mxml/Font.o \
    ../mxml/FormattedText.o \
    ../mxml/Forward.o \
    ../mxml/FrameNote.o \
    ../mxml/Frame.o \
    ../mxml/Fret.o \
    ../mxml/Glissando.o \
    ../mxml/Grace.o \
    ../mxml/GroupBarline.o \
    ../mxml/Grouping.o \
    ../mxml/GroupName.o \
    ../mxml/GroupNameText.o \
    ../mxml/GroupSymbol.o \
    ../mxml/Halign.o \
    ../mxml/HammerOnPullOff.o \
    ../mxml/Handbell.o \
    ../mxml/Harmonic.o \
    ../mxml/HarmonyChord.o \
    ../mxml/Harmony.o \
    ../mxml/HarpPedals.o \
    ../mxml/HeelToe.o \
    ../mxml/HoleClosed.o \
    ../mxml/Hole.o \
    ../mxml/HorizontalTurn.o \
    ../mxml/Identification.o \
    ../mxml/ImageAttributes.o \
    ../mxml/Image.o \
    ../mxml/Instrument.o \
    ../mxml/Interchangeable.o \
    ../mxml/Inversion.o \
    ../mxml/Justify.o \
    ../mxml/Key.o \
    ../mxml/KeyOctave.o \
    ../mxml/Kind.o \
    ../mxml/LetterSpacing.o \
    ../mxml/LevelDisplay.o \
    ../mxml/Level.o \
    ../mxml/LineHeight.o \
    ../mxml/LineShape.o \
    ../mxml/LineType.o \
    ../mxml/LineWidth.o \
    ../mxml/LinkAttributes.o \
    ../mxml/Link.o \
    ../mxml/LyricFont.o \
    ../mxml/LyricLanguage.o \
    ../mxml/Lyric.o \
    ../mxml/MeasureAttributes.o \
    ../mxml/MeasureLayout.o \
    ../mxml/MeasureNumbering.o \
    ../mxml/Measure.o \
    ../mxml/MeasureRepeat.o \
    ../mxml/MeasureStyle.o \
    ../mxml/MetronomeBeam.o \
    ../mxml/MetronomeNote.o \
    ../mxml/MetronomeTuplet.o \
    ../mxml/MidiDevice.o \
    ../mxml/MidiInfo.o \
    ../mxml/MidiInstrument.o \
    ../mxml/MiscellaneousField.o \
    ../mxml/Miscellaneous.o \
    ../mxml/Mordent.o \
    ../mxml/MultipleRest.o \
    ../mxml/NameDisplay.o \
    ../mxml/NonArpeggiate.o \
    ../mxml/NonTraditionalKey.o \
    ../mxml/Notations.o \
    ../mxml/Notehead.o \
    ../mxml/NoteheadText.o \
    ../mxml/Note.o \
    ../mxml/NoteSize.o \
    ../mxml/NoteType.o \
    ../mxml/OctaveShift.o \
    ../mxml/Offset.o \
    ../mxml/Opus.o \
    ../mxml/Orientation.o \
    ../mxml/Ornament.o \
    ../mxml/Ornaments.o \
    ../mxml/OtherAppearance.o \
    ../mxml/OtherDirection.o \
    ../mxml/OtherNotation.o \
    ../mxml/OtherPlay.o \
    ../mxml/PageLayout.o \
    ../mxml/PageMargins.o \
    ../mxml/PartAttributes.o \
    ../mxml/PartGroup.o \
    ../mxml/PartName.o \
    ../mxml/PartNameText.o \
    ../mxml/Part.o \
    ../mxml/PartSymbol.o \
    ../mxml/Pedal.o \
    ../mxml/PedalTuning.o \
    ../mxml/Percussion.o \
    ../mxml/PerMinute.o \
    ../mxml/Pitch.o \
    ../mxml/Placement.o \
    ../mxml/PlacementText.o \
    ../mxml/Position.o \
    ../mxml/PrincipalVoice.o \
    ../mxml/PrintAttributes.o \
    ../mxml/Print.o \
    ../mxml/PrintObject.o \
    ../mxml/Printout.o \
    ../mxml/PrintSpacing.o \
    ../mxml/PrintStyleAlign.o \
    ../mxml/PrintStyle.o \
    ../mxml/Repeat.o \
    ../mxml/Rest.o \
    ../mxml/RootAlter.o \
    ../mxml/Root.o \
    ../mxml/RootStep.o \
    ../mxml/Scaling.o \
    ../mxml/Scordatura.o \
    ../mxml/ScoreInstrument.o \
    ../mxml/ScorePart.o \
    ../mxml/ScorePartwise.o \
    ../mxml/Slash.o \
    ../mxml/Slide.o \
    ../mxml/Slur.o \
    ../mxml/Sound.o \
    ../mxml/StaffDetails.o \
    ../mxml/StaffLayout.o \
    ../mxml/StaffTuning.o \
    ../mxml/Stem.o \
    ../mxml/Stick.o \
    ../mxml/StringMute.o \
    ../mxml/String.o \
    ../mxml/StrongAccent.o \
    ../mxml/StyleText.o \
    ../mxml/Supports.o \
    ../mxml/SystemDividers.o \
    ../mxml/SystemLayout.o \
    ../mxml/SystemMargins.o \
    ../mxml/Technicals.o \
    ../mxml/TextDecoration.o \
    ../mxml/TextDirection.o \
    ../mxml/TextElementData.o \
    ../mxml/TextFontColor.o \
    ../mxml/TextFormatting.o \
    ../mxml/TextRotation.o \
    ../mxml/Tied.o \
    ../mxml/Tie.o \
    ../mxml/TimeModification.o \
    ../mxml/Time.o \
    ../mxml/TimeSignature.o \
    ../mxml/TraditionalKey.o \
    ../mxml/Transpose.o \
    ../mxml/Tremolo.o \
    ../mxml/TrillSound.o \
    ../mxml/TupletDot.o \
    ../mxml/TupletNumber.o \
    ../mxml/Tuplet.o \
    ../mxml/TupletPortion.o \
    ../mxml/TupletType.o \
    ../mxml/TypedText.o \
    ../mxml/Unpitched.o \
    ../mxml/ValignImage.o \
    ../mxml/Valign.o \
    ../mxml/VirtualInstrument.o \
    ../mxml/WavyLine.o \
    ../mxml/Wedge.o \
    ../mxml/Work.o \
    ../mxml/XPosition.o \
    ../mxml/YPosition.o

SOURCES +=\
    Clef.cpp \
    MSvgRenderer.cpp \
    Symbol.cpp \
    main.cpp \
    test/TestClef.cpp

HEADERS  += \
    Clef.h \
    MSvgRenderer.h \
    Symbol.h \
    test/test.h

RESOURCES += \
    resource.qrc
