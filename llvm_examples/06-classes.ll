; ModuleID = '06-classes.cpp'
source_filename = "06-classes.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%class.Foo = type { i32, i8, %class.A* }
%class.A = type { i32 }

$_ZN3FooC2Ei = comdat any

$_ZN3Foo3GetEv = comdat any

$_ZN3Foo3SetEi = comdat any

$_ZN3Foo2GGEi = comdat any

; Function Attrs: noinline norecurse optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca %class.Foo, align 8
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = load i32, i32* %1, align 4
  call void @_ZN3FooC2Ei(%class.Foo* %2, i32 %5)
  %6 = call i32 @_ZN3Foo3GetEv(%class.Foo* %2)
  store i32 %6, i32* %3, align 4
  call void @_ZN3Foo3SetEi(%class.Foo* %2, i32 6)
  %7 = call i32 @_ZN3Foo2GGEi(i32 10)
  store i32 %7, i32* %4, align 4
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN3FooC2Ei(%class.Foo* %0, i32 %1) unnamed_addr #1 comdat align 2 {
  %3 = alloca %class.Foo*, align 8
  %4 = alloca i32, align 4
  store %class.Foo* %0, %class.Foo** %3, align 8
  store i32 %1, i32* %4, align 4
  %5 = load %class.Foo*, %class.Foo** %3, align 8
  %6 = load i32, i32* %4, align 4
  %7 = getelementptr inbounds %class.Foo, %class.Foo* %5, i32 0, i32 0
  store i32 %6, i32* %7, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_ZN3Foo3GetEv(%class.Foo* %0) #1 comdat align 2 {
  %2 = alloca %class.Foo*, align 8
  store %class.Foo* %0, %class.Foo** %2, align 8
  %3 = load %class.Foo*, %class.Foo** %2, align 8
  %4 = getelementptr inbounds %class.Foo, %class.Foo* %3, i32 0, i32 0
  %5 = load i32, i32* %4, align 8
  ret i32 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN3Foo3SetEi(%class.Foo* %0, i32 %1) #1 comdat align 2 {
  %3 = alloca %class.Foo*, align 8
  %4 = alloca i32, align 4
  store %class.Foo* %0, %class.Foo** %3, align 8
  store i32 %1, i32* %4, align 4
  %5 = load %class.Foo*, %class.Foo** %3, align 8
  %6 = load i32, i32* %4, align 4
  %7 = getelementptr inbounds %class.Foo, %class.Foo* %5, i32 0, i32 0
  store i32 %6, i32* %7, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_ZN3Foo2GGEi(i32 %0) #1 comdat align 2 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = add nsw i32 %3, 1
  ret i32 %4
}

attributes #0 = { noinline norecurse optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0-4ubuntu1 "}
