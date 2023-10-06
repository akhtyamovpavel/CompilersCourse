; ModuleID = '06-classes.cpp'
source_filename = "06-classes.cpp"
target datalayout = "e-m:o-i64:64-i128:128-n32:64-S128"
target triple = "arm64-apple-macosx12.0.0"

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
%"class.std::__1::basic_ostream" = type { ptr, %"class.std::__1::basic_ios.base" }
%"class.std::__1::basic_ios.base" = type <{ %"class.std::__1::ios_base", ptr, i32 }>
%"class.std::__1::ios_base" = type { ptr, i32, i64, i64, i32, i32, ptr, ptr, ptr, ptr, i64, i64, ptr, i64, i64, ptr, i64, i64 }
%"class.std::__1::locale::id" = type <{ %"struct.std::__1::once_flag", i32, [4 x i8] }>
%"struct.std::__1::once_flag" = type { i64 }
%"class.std::__1::locale" = type { ptr }

@_ZNSt3__14coutE = external global %"class.std::__1::basic_ostream", align 8
@_ZNSt3__15ctypeIcE2idE = external global %"class.std::__1::locale::id", align 8

; Function Attrs: norecurse ssp uwtable
define noundef i32 @main() local_unnamed_addr #0 personality ptr @__gxx_personality_v0 {
  %1 = alloca %"class.std::__1::locale", align 8
  %2 = tail call noundef nonnull align 8 dereferenceable(8) ptr @_ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEm(ptr noundef nonnull align 8 dereferenceable(8) @_ZNSt3__14coutE, i64 noundef 4)
  %3 = load ptr, ptr %2, align 8, !tbaa !5
  %4 = getelementptr i8, ptr %3, i64 -24
  %5 = load i64, ptr %4, align 8
  %6 = getelementptr inbounds i8, ptr %2, i64 %5
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %1) #4
  call void @_ZNKSt3__18ios_base6getlocEv(ptr nonnull sret(%"class.std::__1::locale") align 8 %1, ptr noundef nonnull align 8 dereferenceable(136) %6)
  %7 = invoke noundef ptr @_ZNKSt3__16locale9use_facetERNS0_2idE(ptr noundef nonnull align 8 dereferenceable(8) %1, ptr noundef nonnull align 8 dereferenceable(12) @_ZNSt3__15ctypeIcE2idE)
          to label %8 unwind label %13

8:                                                ; preds = %0
  %9 = load ptr, ptr %7, align 8, !tbaa !5
  %10 = getelementptr inbounds ptr, ptr %9, i64 7
  %11 = load ptr, ptr %10, align 8
  %12 = invoke noundef signext i8 %11(ptr noundef nonnull align 8 dereferenceable(25) %7, i8 noundef signext 10)
          to label %16 unwind label %13

13:                                               ; preds = %8, %0
  %14 = landingpad { ptr, i32 }
          cleanup
  %15 = call noundef ptr @_ZNSt3__16localeD1Ev(ptr noundef nonnull align 8 dereferenceable(8) %1) #4
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %1) #4
  resume { ptr, i32 } %14

16:                                               ; preds = %8
  %17 = call noundef ptr @_ZNSt3__16localeD1Ev(ptr noundef nonnull align 8 dereferenceable(8) %1) #4
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %1) #4
  %18 = call noundef nonnull align 8 dereferenceable(8) ptr @_ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE3putEc(ptr noundef nonnull align 8 dereferenceable(8) %2, i8 noundef signext %12)
  %19 = call noundef nonnull align 8 dereferenceable(8) ptr @_ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(ptr noundef nonnull align 8 dereferenceable(8) %2)
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

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"uwtable", i32 2}
!3 = !{i32 7, !"frame-pointer", i32 1}
!4 = !{!"Homebrew clang version 15.0.7"}
!5 = !{!6, !6, i64 0}
!6 = !{!"vtable pointer", !7, i64 0}
!7 = !{!"Simple C++ TBAA"}
